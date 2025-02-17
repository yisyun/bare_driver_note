#include "beep.h"

void init_beep(void)
{
    MUX_GPIO5_IO01 = 0x05;
    PAD_GPIO5_IO01 = 0x10B0;
    GPIO5_GDIR |= (1 << 1);
}

void beep_switch(int status)
{
    if (status == ON)
        GPIO5_DR &= ~(1 << 1);
    else
        GPIO5_DR |= (1 << 1);
}