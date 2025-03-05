#include "reg.h"
#include "clk.h"
#include "delay.h"
#include "beep.h"
#include "key.h"
#include "led.h"
#include "uart.h"
#include "int.h"
#include "exint.h"

int main(void)
{
    init_int();
    init_clock();
    enable_clock();
    init_key();
    init_gpio();
    init_beep();
    uart_init();
    exit_init();
    
    beep_switch(OFF);
	puts("hello\n");
    while (1) {
     /*if (get_key() == 1) {
            beep_switch(ON);
            delay(3000);
            beep_switch(OFF);
        }*/
        led_on();
        delay(3000);
        led_off();
        delay(3000);
    }

    return 0;
}

