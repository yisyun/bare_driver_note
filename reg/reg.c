#include "reg.h"

int gpio_pinread(GPIO_Reg *base, int pin)
{
	 return (((base->DR) >> pin) & 0x1);
}

void gpio_pinwrite(GPIO_Reg *base, int pin, int value)
{
	 if (value == 0U)
		base->DR &= ~(1U << pin);
	 else
		base->DR |= (1U << pin);
}

void gpio_enableint(GPIO_Reg* base, unsigned int pin)
{ 
    base->IMR |= (1 << pin);
}

void GIC_Init(void)
{
  uint32_t i;
  uint32_t irqRegs;
  GIC_Type *gic = (GIC_Type *)(__get_CBAR() & 0xFFFF0000UL);

  irqRegs = (gic->D_TYPER & 0x1FUL) + 1;

  //On POR, all SPI is in group 0, level-sensitive and using 1-N model

  // Disable all PPI, SGI and SPI
  for (i = 0; i < irqRegs; i++)
    gic->D_ICENABLER[i] = 0xFFFFFFFFUL;

  // Make all interrupts have higher priority
  gic->C_PMR = (0xFFUL << (8 - 5)) & 0xFFUL;

  // No subpriority, all priority level allows preemption
  gic->C_BPR = 7 - 5;

  // Enable group0 distribution
  gic->D_CTLR = 1UL;

  // Enable group0 signaling
  gic->C_CTLR = 1UL;
}

void GIC_EnableIRQ_99(void)
{
  	GIC_Type *gic = (GIC_Type *)(__get_CBAR() & 0xFFFF0000UL);
  	gic->D_ISENABLER[((uint32_t)(int32_t)99) >> 5] = (uint32_t)(1UL << (((uint32_t)(int32_t)99) & 0x1FUL));
}