#include <stddef.h>
#include "int.h"

sys_irq_handler_t irq_table[IRQ_NUM];

void default_irq_handler(unsigned int int_id, void* user_parem)
{

}

void irq_handler_register(unsigned int int_id,
                system_irq_handler_t irqhandler,
                void *userparam)
{
    irq_table[int_id].irq_handler = irqhandler;
    irq_table[int_id].userparam = userparam;
}

void irq_table_init()
{
    for (unsigned int i = 0; i < IRQ_NUM; i++)
        irq_handler_register(i, default_irq_handler, NULL);
}

void system_irq_handler(unsigned int int_id, void *userparam)
{
    irq_table[int_id].irq_handler(int_id, irq_table[int_id].userparam);
}

void init_int(void)
{
    GIC_Init();
    irq_table_init();
}