#ifndef __UART_H
#define __UART_H
#include "reg.h"

void uart_init(void);
void putc(unsigned char c);
unsigned char getc(void);
void puts(char *str);

#endif