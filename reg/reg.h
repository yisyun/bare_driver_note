#ifndef __REG_H
#define __REG_H

#define CCM_CCGR0       *((volatile unsigned int *)0x020C4068)
#define CCM_CCGR1       *((volatile unsigned int *)0x020C406C)
#define CCM_CCGR2       *((volatile unsigned int *)0x020C4070)
#define CCM_CCGR3       *((volatile unsigned int *)0x020C4074)
#define CCM_CCGR4       *((volatile unsigned int *)0x020C4078)
#define CCM_CCGR5       *((volatile unsigned int *)0x020C407C)
#define CCM_CCGR6       *((volatile unsigned int *)0x020C4080)
#define MUX_GPIO1_IO03  *((volatile unsigned int *)0x020E0068)
#define PAD_GPIO1_IO03  *((volatile unsigned int *)0x020E02F4)
#define GPIO1_GDIR      *((volatile unsigned int *)0x0209C004)
#define GPIO1_DR        *((volatile unsigned int *)0x0209C000)

#define CCM_CCSR        *((volatile unsigned int *)0x020C400C)
#define CCM_ANALOG_PLL_ARM        *((volatile unsigned int *)0x020C8000)
#define CCM_CACRR        *((volatile unsigned int *)0x020C4000)

#define MUX_GPIO5_IO01  *((volatile unsigned int *)0x020E0020)
#define PAD_GPIO5_IO01  *((volatile unsigned int *)0x020E02AC)
#define GPIO5_DR        *((volatile unsigned int *)0x020AC000)
#define GPIO5_GDIR      *((volatile unsigned int *)0x020AC004)

#define MUX_GPIO1_IO18      *((volatile unsigned int *)0x020E008C)
#define PAD_GPIO1_IO18      *((volatile unsigned int *)0x020E0318)

#define UART1_URXD      *((volatile unsigned int *)0x02020000)
#define UART1_UTXD      *((volatile unsigned int *)0x02020040)
#define UART1_UCR1      *((volatile unsigned int *)0x02020080)
#define UART1_UCR2      *((volatile unsigned int *)0x02020084)
#define UART1_UCR3      *((volatile unsigned int *)0x02020088)
#define UART1_UCR4      *((volatile unsigned int *)0x0202008C)
#define UART1_UFCR      *((volatile unsigned int *)0x02020090)
#define UART1_UBIR      *((volatile unsigned int *)0x020200A4)
#define UART1_UBMR      *((volatile unsigned int *)0x020200A8)
#define UART1_USR2      *((volatile unsigned int *)0x02020098)

#define MUX_UART1_TX      *((volatile unsigned int *)0x020E0084)
#define MUX_UART1_RX      *((volatile unsigned int *)0x020E0088)
#define PAD_UART1_TX      *((volatile unsigned int *)0x020E0310)
#define PAD_UART1_RX      *((volatile unsigned int *)0x020E0314)

#endif