#define SYSLIB_HPP
#ifdef SYSLIB_HPP

/***
 * レジスタアクセス用関数
 ***/
// 32bitレジスタからの入力
static inline UW in_w(UW adr)
{
    return *(_UW*)adr;
}

// 32bitレジスタへの出力
static inline void out_w(UW adr, UW data)
{
    *(_UW*)adr = data;
}

// 32bitレジスタへの出力(XOR on write)
// Atomic Register Access機能を利用
#define OP_ARA_XOR  0x1000
static inline void xset_w(UW adr, UW data)
{
    *(_UW*)(adr + OP_ARA_XOR) = data;
}

// 32bitレジスタへの出力(set on write)
// Atomic Register Access機能を利用
#define OP_ARA_SET  0x2000
static inline void set_w(UW adr, UW data)
{
    *(_UW*)(adr + OP_ARA_SET) = data;
}

// 32bitレジスタへの出力(clear on write)
// Atomic Register Access機能を利用
#define OP_ARA_CLR  0x3000
static inline void clr_w(UW adr, UW data)
{
    *(_UW*)(adr + OP_ARA_CLR) = data;
}


/***
 * 割込み制御
 ***/
/**
 * @brief PRIMASKレジスタにvalueを設定する
 * [0]をセットすると、設定可能な優先度を持つすべての例外が禁止される
 *
 * @param value
 */
static inline void __set_PRIMASK(UW value)
{
    __asm__ volatile("MSR PRIMASK, %0" :: "r"(value));
}
/**
 * @brief PRIMASKレジスタの値を取得する
 *
 * @return PRIMASKレジスタの現在の値
 */
static inline UW __get_PRIMASK(void)
{
    UW value;
    __asm__ volatile("MRS PRIMASK, %0" : "=r"(value));
    return value;
}

/* 割込み禁止マクロ */
#define DI(value) (value = __get_PRIMASK(), __set_PRIMASK(1))

/* 割込み許可マクロ */
#define EI(value) (__set_PRIMASK(value))

#endif
