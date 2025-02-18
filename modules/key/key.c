#include "key.h"
#include "delay.h"

void init_key(void)
{
    MUX_GPIO1_IO03 = 0x5;
    PAD_GPIO1_IO03 = 0xF080;
}

int get_key(void)
{
    static unsigned char release = 1;

    if (release && ((GPIO1_DR >> 18) & 0x1) == 0) {
        delay(10);
        release = 0;
        if (((GPIO1_DR >> 18) & 0x1) == 0)
            return 1;
    } else {
        release = 1;
        return 0;
    }

    return 0;
}