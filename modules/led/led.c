#include "led.h"

void init_gpio(void)
{
    MUX_GPIO1_IO03 = 0x5;
    PAD_GPIO1_IO03 = 0x10B0;
    GPIO1_GDIR = 0x00000008;
    GPIO1_DR = 0x0;
}

void led_on(void)
{
 GPIO1_DR &= ~(1<<3);
}

void led_off(void)
{
 GPIO1_DR |= (1<<3);
}