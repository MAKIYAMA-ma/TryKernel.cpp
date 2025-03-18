/* 
 *** Try Kernel
 *      例外ベクターテーブル
*/

#include <typedef.h>
#include <sysdef.h>
#include <syslib.h>
#include <knldef.h>

/***************************************************
 * 割込みハンドラのクラス定義
 ***************************************************/
class InterruptHandler
{
    public:
        virtual void handle() = 0;
}

class DefaultInterrupt : public InterruptHandler
{
    public:
        void handle() override;
};

class ResetInterrupt : public InterruptHandler
{
    public:
        void handle() override;
};


/***************************************************
 * ベクタテーブル登録用のISRラッパー関数宣言
 * 内部的には、InterruptHandlerの実装クラスのhandleの呼び出し
 ***************************************************/
extern "C" void Default_Handler();
extern "C" void Reset_Handler();
