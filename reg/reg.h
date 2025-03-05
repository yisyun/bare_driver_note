#ifndef __REG_H
#define __REG_H
#include <stdint.h>
#include <stddef.h>

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
#define GPIO1           *((volatile unsigned int *)0x0209C000)

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

#define __get_CBAR()                              \
  ({                                                                              \
      uint32_t __dst;                                                               \
      __asm volatile ("MRC  p15, 4, %0, c15, c0, 0":"=r" (__dst) );                 \
      __dst;                                                                        \
  })




typedef struct
{
      uint32_t RESERVED0[1024];
      volatile  uint32_t D_CTLR;                 /*!< Offset: 0x1000 (R/W) Distributor Control Register */
      volatile  uint32_t D_TYPER;                /*!< Offset: 0x1004 (R/ )  Interrupt Controller Type Register */
      volatile  uint32_t D_IIDR;                 /*!< Offset: 0x1008 (R/ )  Distributor Implementer Identification Register */
      uint32_t RESERVED1[29];
      volatile uint32_t D_IGROUPR[16];          /*!< Offset: 0x1080 - 0x0BC (R/W) Interrupt Group Registers */
      uint32_t RESERVED2[16];
      volatile uint32_t D_ISENABLER[16];        /*!< Offset: 0x1100 - 0x13C (R/W) Interrupt Set-Enable Registers */
      uint32_t RESERVED3[16];
      volatile uint32_t D_ICENABLER[16];        /*!< Offset: 0x1180 - 0x1BC (R/W) Interrupt Clear-Enable Registers */
      uint32_t RESERVED4[16];
      volatile uint32_t D_ISPENDR[16];          /*!< Offset: 0x1200 - 0x23C (R/W) Interrupt Set-Pending Registers */
      uint32_t RESERVED5[16];
      volatile uint32_t D_ICPENDR[16];          /*!< Offset: 0x1280 - 0x2BC (R/W) Interrupt Clear-Pending Registers */
      uint32_t RESERVED6[16];
      volatile uint32_t D_ISACTIVER[16];        /*!< Offset: 0x1300 - 0x33C (R/W) Interrupt Set-Active Registers */
      uint32_t RESERVED7[16];
      volatile uint32_t D_ICACTIVER[16];        /*!< Offset: 0x1380 - 0x3BC (R/W) Interrupt Clear-Active Registers */
      uint32_t RESERVED8[16];
      volatile uint8_t  D_IPRIORITYR[512];      /*!< Offset: 0x1400 - 0x5FC (R/W) Interrupt Priority Registers */
      uint32_t RESERVED9[128];
      volatile uint8_t  D_ITARGETSR[512];       /*!< Offset: 0x1800 - 0x9FC (R/W) Interrupt Targets Registers */
      uint32_t RESERVED10[128];
      volatile uint32_t D_ICFGR[32];            /*!< Offset: 0x1C00 - 0xC7C (R/W) Interrupt configuration registers */
      uint32_t RESERVED11[32];
      volatile  uint32_t D_PPISR;                /*!< Offset: 0x1D00 (R/ ) Private Peripheral Interrupt Status Register */
      volatile  uint32_t D_SPISR[15];            /*!< Offset: 0x1D04 - 0xD3C (R/ ) Shared Peripheral Interrupt Status Registers */
      uint32_t RESERVED12[112];
      volatile  uint32_t D_SGIR;                 /*!< Offset: 0x1F00 ( /W) Software Generated Interrupt Register */
      uint32_t RESERVED13[3];
      volatile uint8_t  D_CPENDSGIR[16];        /*!< Offset: 0x1F10 - 0xF1C (R/W) SGI Clear-Pending Registers */
      volatile uint8_t  D_SPENDSGIR[16];        /*!< Offset: 0x1F20 - 0xF2C (R/W) SGI Set-Pending Registers */
      uint32_t RESERVED14[40];
      volatile  uint32_t D_PIDR4;                /*!< Offset: 0x1FD0 (R/ ) Peripheral ID4 Register */
      volatile  uint32_t D_PIDR5;                /*!< Offset: 0x1FD4 (R/ ) Peripheral ID5 Register */
      volatile  uint32_t D_PIDR6;                /*!< Offset: 0x1FD8 (R/ ) Peripheral ID6 Register */
      volatile  uint32_t D_PIDR7;                /*!< Offset: 0x1FDC (R/ ) Peripheral ID7 Register */
      volatile  uint32_t D_PIDR0;                /*!< Offset: 0x1FE0 (R/ ) Peripheral ID0 Register */
      volatile  uint32_t D_PIDR1;                /*!< Offset: 0x1FE4 (R/ ) Peripheral ID1 Register */
      volatile  uint32_t D_PIDR2;                /*!< Offset: 0x1FE8 (R/ ) Peripheral ID2 Register */
      volatile  uint32_t D_PIDR3;                /*!< Offset: 0x1FEC (R/ ) Peripheral ID3 Register */
      volatile  uint32_t D_CIDR0;                /*!< Offset: 0x1FF0 (R/ ) Component ID0 Register */
      volatile  uint32_t D_CIDR1;                /*!< Offset: 0x1FF4 (R/ ) Component ID1 Register */
      volatile  uint32_t D_CIDR2;                /*!< Offset: 0x1FF8 (R/ ) Component ID2 Register */
      volatile  uint32_t D_CIDR3;                /*!< Offset: 0x1FFC (R/ ) Component ID3 Register */

      volatile uint32_t C_CTLR;                 /*!< Offset: 0x2000 (R/W) CPU Interface Control Register */
      volatile uint32_t C_PMR;                  /*!< Offset: 0x2004 (R/W) Interrupt Priority Mask Register */
      volatile uint32_t C_BPR;                  /*!< Offset: 0x2008 (R/W) Binary Point Register */
      volatile  uint32_t C_IAR;                  /*!< Offset: 0x200C (R/ ) Interrupt Acknowledge Register */
      volatile  uint32_t C_EOIR;                 /*!< Offset: 0x2010 ( /W) End Of Interrupt Register */
      volatile  uint32_t C_RPR;                  /*!< Offset: 0x2014 (R/ ) Running Priority Register */
      volatile  uint32_t C_HPPIR;                /*!< Offset: 0x2018 (R/ ) Highest Priority Pending Interrupt Register */
      volatile uint32_t C_ABPR;                 /*!< Offset: 0x201C (R/W) Aliased Binary Point Register */
      volatile  uint32_t C_AIAR;                 /*!< Offset: 0x2020 (R/ ) Aliased Interrupt Acknowledge Register */
      volatile  uint32_t C_AEOIR;                /*!< Offset: 0x2024 ( /W) Aliased End Of Interrupt Register */
      volatile  uint32_t C_AHPPIR;               /*!< Offset: 0x2028 (R/ ) Aliased Highest Priority Pending Interrupt Register */
      uint32_t RESERVED15[41];
      volatile uint32_t C_APR0;                 /*!< Offset: 0x20D0 (R/W) Active Priority Register */
      uint32_t RESERVED16[3];
      volatile uint32_t C_NSAPR0;               /*!< Offset: 0x20E0 (R/W) Non-secure Active Priority Register */
      uint32_t RESERVED17[6];
      volatile  uint32_t C_IIDR;                 /*!< Offset: 0x20FC (R/ ) CPU Interface Identification Register */
      uint32_t RESERVED18[960];
      volatile  uint32_t C_DIR;                  /*!< Offset: 0x3000 ( /W) Deactivate Interrupt Register */
} GIC_Type;

typedef struct GPIO_Type {
      volatile unsigned int DR;
      volatile unsigned int GDIR;
      volatile unsigned int PSR;
      volatile unsigned int ICR1;
      volatile unsigned int ICR2;
      volatile unsigned int IMR;
      volatile unsigned int ISR;
      volatile unsigned int EDGE_SEL;
} GPIO_Reg;

int gpio_pinread(GPIO_Reg *base, int pin);
void gpio_pinwrite(GPIO_Reg *base, int pin, int value);
void gpio_enableint(GPIO_Reg* base, unsigned int pin);
void GIC_Init(void);
void GIC_EnableIRQ_99(void);

#endif