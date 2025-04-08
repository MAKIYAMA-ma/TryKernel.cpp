#ifndef KNLDEF_HPP
#define KNLDEF_HPP

#include "typedef.h"
/* #include "sysdef.hpp" */
/* #include "syslib.hpp" */

class Main
{
    public:
        void main();
        void delay_ms(UINT ms);
};

extern "C" int main();

#endif // KNLDEF_HPP
