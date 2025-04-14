#include "typedef.h"
#include "sysdef.hpp"
#include "syslib.hpp"
#include "isr.hpp"

/* メモリセクションのアドレス変数 */
extern const void *__data_org;
extern const void *__data_start;
extern const void *__data_end;
extern const void *__bss_start;
extern const void *__bss_end;

/**
 * @brief PLLの初期化
 * とりあえず、公式SDKと同じ設定を試みる
 *
 * @param pll 対象PLLのBASE
 * @param refdiv
 * @param vco_freq
 * @param post_div1
 * @param post_div2
 */
void ResetInterrupt::init_pll(ResetInterrupt::PLL pll, UINT refdiv, UINT vco_freq, UINT post_div1, UINT post_div2)
{
    UINT ref_freq = XOSC_HZ / refdiv;
    UINT fbdiv = vco_freq / ref_freq;

    UINT pdiv = (post_div1 << PLL_PRIM_POSTDIV1_LSB) |
                (post_div2 << PLL_PRIM_POSTDIV2_LSB);

    UW pll_reset = (pll == PLL::PLL_SYS) ? RESETS_RESET_BIT_PLL_SYS : RESETS_RESET_BIT_PLL_USB;
    set_w(RESETS_RESET, pll_reset);
    clr_w(RESETS_RESET, pll_reset);
    while (!(in_w((UW)RESETS_RESET_DONE) & pll_reset));

    out_w((UW)pll+PLL_CS_OFFSET, refdiv);
    out_w((UW)pll+PLL_FBDIV_INT_OFFSET, fbdiv);
    clr_w((UW)pll+PLL_PWR_OFFSET, PLL_PWR_BIT_PD | PLL_PWR_BIT_VCOPD);

    while (!(in_w((UW)pll+PLL_CS_OFFSET) & PLL_CS_BIT_LOCK));

    out_w((UW)pll+PLL_PRIM_OFFSET, pdiv);
    clr_w((UW)pll+PLL_PWR_OFFSET, PLL_PWR_BIT_POSTDIVPD);
}

/**
 * @brief クロック設定関数
 */
void ResetInterrupt::clock_config(UINT type, UINT src, UINT auxsrc, UINT src_freq, UINT freq)
{
    if(freq > src_freq) return;

    UD div64 = ((((UD) src_freq) << 8) / freq);
    UW div, actual_div;

    if(div64 >> 32) {
        div = 0;
        actual_div = src_freq >> (32-8);
    } else {
        div = (UW)div64;
        actual_div = (UW)((((UD) src_freq) << 8) / div);
    }

    if(div > in_w(CLOCKS_BASE+type+CLK_DIV_OFFSET)) {
        out_w(CLOCKS_BASE+type+CLK_DIV_OFFSET, div);
    }

    if(type == CLK_TYPE_SYS || type == CLK_TYPE_REF) {
        clr_w(CLOCKS_BASE+type+CLK_CTRL_OFFSET, 0x00000003);
        while (!(in_w(CLOCKS_BASE+type+CLK_SELECTED_OFFSET) & 0x00000001));
    } else {
        clr_w(CLOCKS_BASE+type+CLK_CTRL_OFFSET, CLK_SYS_CTRL_ENABLE_BITS);
    }

    out_w(CLOCKS_BASE+type+CLK_CTRL_OFFSET,
            (in_w(CLOCKS_BASE+type+CLK_CTRL_OFFSET) & ~CLK_SYS_CTRL_AUXSRC_BITS) |
            (auxsrc << CLK_SYS_CTRL_AUXSRC_LSB));

    if(type == CLK_TYPE_SYS || type == CLK_TYPE_REF) {
        out_w(CLOCKS_BASE+type+CLK_CTRL_OFFSET,
                (in_w(CLOCKS_BASE+type+CLK_CTRL_OFFSET) & ~CLK_REF_CTRL_SRC_BITS) |
                (src << CLK_REF_CTRL_SRC_LSB));
        while (!(in_w(CLOCKS_BASE+type+CLK_SELECTED_OFFSET) & (0x00000001 << src)));
    }

    // this code has no effect when selected clock is SYS or REF
    set_w(CLOCKS_BASE+type+CLK_CTRL_OFFSET, CLK_SYS_CTRL_ENABLE_BITS);

    out_w(CLOCKS_BASE+type+CLK_DIV_OFFSET, div);
}

/**
 * @brief クロック初期化
 */
void ResetInterrupt::init_clock()
{
    out_w(CLK_SYS_RESUS_CTRL, 0);

    init_xosc();

    clr_w(CLOCKS_BASE+CLK_TYPE_SYS+CLK_CTRL_OFFSET, CLK_REF_CTRL_SRC_BITS);
    while (!(in_w(CLOCKS_BASE+CLK_TYPE_SYS+CLK_SELECTED_OFFSET) & 0x00000001));
    clr_w(CLOCKS_BASE+CLK_TYPE_REF+CLK_CTRL_OFFSET, CLK_REF_CTRL_SRC_BITS);
    while (!(in_w(CLOCKS_BASE+CLK_TYPE_REF+CLK_SELECTED_OFFSET) & 0x00000001));

    init_pll(PLL::PLL_SYS, 1, 1500*MHz, 6, 2);
    init_pll(PLL::PLL_USB, 1, 1200*MHz, 5, 5);

    clock_config(CLK_TYPE_REF, 0x02, 0, 12*MHz, 12*MHz);
    clock_config(CLK_TYPE_SYS, 0x01, 0, SYS_HZ, SYS_HZ);
    clock_config(CLK_TYPE_USB, 0, 0, 48*MHz, 48*MHz);
    clock_config(CLK_TYPE_ADC, 0, 0, 48*MHz, 48*MHz);
    clock_config(CLK_TYPE_RTC, 0, 0, 48*MHz, 46875);
    clock_config(CLK_TYPE_PERI, 0, 0, 125*MHz, 125*MHz);
}

/**
 * @brief ペリフェラル初期化
 */
void ResetInterrupt::init_peripherals()
{
    // GPIO
    // UART0
    // のリセットを解除
    UW tgt = RESETS_BIT_IO_BANK0 | RESETS_BIT_PADS_BANK0 | RESETS_BIT_UART0;
    clr_w(RESETS_RESET, tgt);
    while((!(in_w(RESETS_RESET_DONE) & tgt)) == tgt);
}

/**
 * @brief メモリ初期化
 */
void ResetInterrupt::init_mem()
{
    // 初期値のあるグローバル変数の初期化
    _UW *src = (_UW*)&__data_org;
    _UW *dst = (_UW*)&__data_start;
    _UW *end = (_UW*)&__data_end;
    while(dst != end) {
        *dst++ = *src++;
    }

    // 初期値がないグローバル変数の初期化
    dst = (_UW*)&__bss_start;
    end = (_UW*)&__bss_end;
    while(dst != end) {
        *dst++ = 0;
    }
}

/**
 * @brief XOSC初期化
 */
void ResetInterrupt::init_xosc()
{
    out_w(XOSC_CTRL, XOSC_CTRL_FREQ_RQNGE_1_15MHZ);
    out_w(XOSC_STARTUP, ((((XOSC_HZ / KHz) + 128) / 256) * 64));
    set_w(XOSC_CTRL, (XOSC_CTRL_ENABLE << XOSC_CTRL_ENABLE_LSB));
    while (!(in_w(XOSC_STATUS) & XOSC_STATUS_STABLE_BITS));
}

/**
 * @brief タイマの初期化
 * CPU Clock(125MHz)を入力として使用
 * 10msecカウンタとする
 */
void ResetInterrupt::init_systimer()
{
    out_w(SYST_CSR, SYST_CSR_CLKSOURCE);    // SysTick停止
    out_w(SYST_RVR, (TIMER_PERIOD_MS*SYS_HZ/1000)-1);
    out_w(SYST_CVR, (TIMER_PERIOD_MS*SYS_HZ/1000)-1);
    out_w(SYST_CSR, SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE);  // SysTick動作開始
}

void ResetInterrupt::handle()
{
    init_xosc();
    init_clock();
    init_peripherals();
    init_mem();
    init_systimer();

    // TODO
    main();
    while(1);
}
extern "C" void Reset_Handler()
{
    static ResetInterrupt isr;
    isr.handle();
}
