#include "uart.h"

void uart_disable(void)
{
    UART1_UCR1 &= ~(1 << 0);
}

void uart_enable(void)
{
    UART1_UCR1 |= (1 << 0);
}

void uart_softreset(void)
{
    UART1_UCR2 &= ~(1 << 0);
    while ((UART1_UCR2 & 0x1) == 0);
}

void uart_io_init(void)
{
    MUX_UART1_TX = 0x0;
    MUX_UART1_RX = 0x0;
    PAD_UART1_TX = 0x10B0;
    PAD_UART1_RX = 0x10B0;
}

void uart_init(void)
{
    uart_io_init();

    uart_disable();
    uart_softreset();
    UART1_UCR1 = 0;
    UART1_UCR1 &= ~(1 << 14);

    UART1_UCR2 |= (1 << 14) | (1 << 5) | (1 << 2) | (1 << 1);
    UART1_UCR3 |= 1 << 2;

    UART1_UFCR = 5 << 7;
    UART1_UBIR = 71;
    UART1_UBMR = 3124;

    uart_enable();
}

void putc(unsigned char c)
{
    while (((UART1_USR2 >> 3) & 0x01) == 0);
    UART1_UTXD = c & 0xFF;
}

unsigned char getc(void)
{
    while ((UART1_USR2 & 0x1) == 0);
    return UART1_URXD;
}

void puts(char *str)
{
    char *p = str;
    while (*p)
        putc(*p++);
}
