#ifndef ISR_HPP
#define ISR_HPP
/* 
 *** Try Kernel
 *      例外ベクターテーブル
*/

#include "typedef.h"
#include "sysdef.hpp"
#include "syslib.hpp"
#include "knldef.h"

/***************************************************
 * 割込みハンドラのクラス定義
 ***************************************************/
class InterruptHandler
{
    public:
        virtual void handle() = 0;
};

class DefaultInterrupt : public InterruptHandler
{
    public:
        void handle() override;
};

class ResetInterrupt : public InterruptHandler
{
    public:
        void handle() override;
    private:
        enum class PLL {
            PLL_SYS = PLL_SYS_BASE,
            PLL_USB = PLL_USB_BASE,
        };
        /**
         * @brief PLL初期化
         */
        void init_pll(PLL pll, UINT refdiv, UINT vco_freq, UINT post_div1, UINT post_div2);
        /**
         * @brief クロック設定関数
         */
        void clock_config(UINT type, UINT src, UINT auxsrc, UINT src_freq, UINT freq);
        /**
         * @brief クロック初期化
         */
        void init_clock();
        /**
         * @brief ペリフェラル初期化
         */
        void init_peripherals();
        /**
         * @brief メモリ初期化
         */
        void init_mem();
        /**
         * @brief メモリ初期化
         */
        void init_xosc();
        /**
         * @brief XOSCの初期化
         */
        void init_systimer();
};


/***************************************************
 * ベクタテーブル登録用のISRラッパー関数宣言
 * 内部的には、InterruptHandlerの実装クラスのhandleの呼び出し
 ***************************************************/
extern "C" void Default_Handler();
extern "C" void Reset_Handler();

#endif
