#include "led.h"

void enable_clock(void)
{
    CCM_CCGR0 = 0xFFFFFFFF;
    CCM_CCGR1 = 0xFFFFFFFF;
    CCM_CCGR2 = 0xFFFFFFFF;
    CCM_CCGR3 = 0xFFFFFFFF;
    CCM_CCGR4 = 0xFFFFFFFF;
    CCM_CCGR5 = 0xFFFFFFFF;
    CCM_CCGR6 = 0xFFFFFFFF;
}

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

void delay_short(volatile unsigned int n) {
    while (n--){}
}

void delay(volatile unsigned int n)
{
    while (n--) {
        delay_short(0x7ff);
    }
}


int main(void)
{
    enable_clock();
    init_gpio();

    while (1) {
    led_on();
    delay(200);
    led_off();
    delay(1000);
    }

    return 0;

}
