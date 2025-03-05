#ifndef __INT_H
#define __INT_H
#include "reg.h"

#define IRQ_NUM 160

typedef void (*system_irq_handler_t)(unsigned int int_id, void *param);

typedef  struct sys_irq_handler {
    system_irq_handler_t irq_handler;
    void *userparam;
} sys_irq_handler_t;

void init_int();
void irq_handler_register(unsigned int int_id, system_irq_handler_t irqhandler,
                                                            void *userparam);
#endif