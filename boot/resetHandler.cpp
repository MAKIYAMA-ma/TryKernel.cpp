#include <typedef.h>
#include <sysdef.h>
#include <syslib.h>
#include <knldef.h>
#include <isr.hpp>

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
ResetInterrupt::init_pll(PLL pll, UINT refdiv, UINT vco_freq, UINT post_div1, UINT post_div2)
{
    UINT ref_freq = XOSC_HZ / refdiv;
    UINT fbdiv = vco_freq / ref_freq;

    UINT pdiv = (post_div1 << PLL_PRIM_POSTDIV1_LSB) |
                (post_div2 << PLL_PRIM_POSTDIV2_LSB);

    UW pll_reset = (pll == PLL_SYS) ? RESETS_RESET_BIT_PLL_SYS : RESETS_RESET_BIT_PLL_USB;
    set_w(RESETS_RESET, pll_reset);
    clr_w(RESETS_RESET, pll_reset);
    while (!(in_w(pll+RESETS_RESET_DONE) & pll_reset));

    out_w(pll+PLL_CS_OFFSET, refdiv);
    out_w(pll+PLL_FBDIV_INT_OFFSET, fbdiv);
    clr_w(pll+PLL_PWR_OFFSET, PLL_PWR_BIT_PD | PLL_PWR_BIT_VCOPD);

    while (!(in_w(pll+PLL_CS_OFFSET) & PLL_CS_BIT_LOCK));

    out_w(pll+PLL_PRIM_OFFSET, pdiv);
    clr_w(pll+PLL_PWR_OFFSET, PLL_PWR_BIT_POSTDIVPD);
}

/**
 * @brief クロック初期化
 */
ResetInterrupt::init_clock()
{
}

/**
 * @brief ペリフェラル初期化
 */
ResetInterrupt::init_pripherals()
{
}

/**
 * @brief メモリ初期化
 */
ResetInterrupt::init_mem()
{
}

/**
 * @brief タイマの初期化
 */
ResetInterrupt::init_systimer()
{
}

ResetInterrupt::handle()
{
    // TODO
    while(1);
}
extern "C" void Reset_Handler()
{
    static ResetInterrupt isr;
    isr.handle();
}
