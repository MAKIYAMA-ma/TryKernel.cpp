#include "typedef.h"
#include "sysdef.hpp"
#include "syslib.hpp"
#include "knldef.h"
#include "isr.hpp"

void DefaultInterrupt::handle()
{
    while(1);
}
extern "C" void Default_Handler()
{
    static DefaultInterrupt isr;
    isr.handle();
}
