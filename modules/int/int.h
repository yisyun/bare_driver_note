#ifndef __INT_H
#define __INT_H
#include "reg.h"

#define IRQ_NUM 160

typedef void (*system_irq_handler_t)(unsigned int int_id, void *param);

typedef  sys_irq_handler {
    system_irq_handler_t irq_handler;
    void *userparam;
} sys_irq_handler_t;

system_irq_handler_t irq_table[IRQ_NUM];

#endif