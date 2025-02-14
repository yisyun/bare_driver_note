#include "reg.h"
#include "clk.h"
#include "delay.h"
#include "led.h"

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
