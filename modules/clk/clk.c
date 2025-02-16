#include "clk.h"

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

void init_clock(void)
{

    CCM_CCSR &= ~(1 << 8); //step_sel
    CCM_CCSR |= (1 << 2); //pll1_sw_clk_sel

    CCM_ANALOG_PLL_ARM &= ~(0x7F);
    CCM_ANALOG_PLL_ARM |= (1 << 13) | (66 << 0);

    CCM_CCSR &= ~(1 << 2);
    CCM_CACRR = 0;
}