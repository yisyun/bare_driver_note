#include "reg.h"
#include "clk.h"
#include "delay.h"
#include "led.h"

int main(void)
{
    init_clock();
    enable_clock();
    init_gpio();

    while (1) {
    led_on();
    delay(30000);
    led_off();
    delay(30000);
    }

    return 0;
}
