#include "reg.h"
#include "clk.h"
#include "delay.h"
#include "beep.h"
#include "led.h"

int main(void)
{
    init_clock();
    enable_clock();
    init_gpio();
    init_beep();

    while (1) {
        led_on();
        beep_switch(ON);
        delay(3000);
        led_off();
        beep_switch(OFF);
        delay(3000);
    }

    return 0;
}
