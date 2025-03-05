
#include "exint.h"
#include "beep.h"
#include "key.h"
#include "delay.h"
#include "int.h"
#include "uart.h"
void gpio1_io18_irqhandler(unsigned int int_id, void *userparam)
{
	puts("hello interrupt\n");
	delay(1000);
}

void gpio_intconfig(GPIO_Reg* base, unsigned int pin)
{
	volatile uint32_t *icr;
	uint32_t icrShift;

	icrShift = pin;

	if (pin < 16) {
		icr = &(base->ICR1);
	} else {
		icr = &(base->ICR2);
		icrShift -= 16;
	}

	*icr |= (3U << (2 * icrShift));
}

/*IMR GDIR ICR*/
void gpio_init(GPIO_Reg *base, int pin)
{
	base->IMR &= ~(1U << pin);
	base->GDIR &= ~( 1 << pin);
	gpio_intconfig(base, pin);
}

void exit_init(void)
{
	MUX_GPIO1_IO18 = 0x5;
    PAD_GPIO1_IO18 = 0xF080;

	gpio_init((GPIO_Reg *)&GPIO1, 18);
	GIC_EnableIRQ_99();
	irq_handler_register(99, gpio1_io18_irqhandler, NULL);		
    ((GPIO_Reg *)&GPIO1)->IMR |= (1 << 18);
}
