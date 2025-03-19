#include <typedef.h>
#include <sysdef.h>
#include <syslib.h>
#include <knldef.h>
#include <isr.hpp>

DefaultInterrupt::handle()
{
    while(1);
}
extern "C" void Default_Handler()
{
    static DefaultInterrupt isr;
    isr.handle();
}
