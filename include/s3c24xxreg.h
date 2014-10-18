#ifndef	S3C2410_REG_H 
#define	S3C2410_REG_H



// Memory Controller
#define MEMCON_BASE     0x48000000
#define BWSCON                0x00
#define BANKCON0              0x04
#define BANKCON1              0x08
#define BANKCON2              0x0c
#define BANKCON3              0x10
#define BANKCON4              0x14
#define BANKCON5              0x18
#define BANKCON6              0x1c
#define BANKCON7              0x20
#define REFRESH               0x24
#define BANKSIZE              0x28
#define MRSB6                 0x2c
#define MRSB7                 0x30

// SDRAM
#define SDRAM_BASE      0x30000000
#define SDRAM_SIZE      0x04000000


// Interrupt Controller
#define INTCON_BASE     0x4a000000
#define SRCPNG                0x00
#define INTMOD                0x04
#define INTMASK               0x08
#define INTPNG                0x10
#define INTOFFSET             0x14
#define SUBMASK               0x1c

#define S3C2410_IRQREG(x)   ((x) + INTCON_BASE)
#define S3C2410_EINTREG(x)  ((x) + GPIO_BASE)

#define S3C2410_SRCPND	       S3C2410_IRQREG(0x000)
#define S3C2410_INTMOD	       S3C2410_IRQREG(0x004)
#define S3C2410_INTMSK	       S3C2410_IRQREG(0x008)
#define S3C2410_PRIORITY       S3C2410_IRQREG(0x00C)
#define S3C2410_INTPND	       S3C2410_IRQREG(0x010)
#define S3C2410_INTOFFSET      S3C2410_IRQREG(0x014)
#define S3C2410_SUBSRCPND      S3C2410_IRQREG(0x018)
#define S3C2410_INTSUBMSK      S3C2410_IRQREG(0x01C)

#define S3C2410_EINTMASK       S3C2410_EINTREG(0x0A4)
#define S3C2410_EINTPEND       S3C2410_EINTREG(0X0A8)

#define S3C2412_EINTMASK       S3C2410_EINTREG(0x0B4)
#define S3C2412_EINTPEND       S3C2410_EINTREG(0X0B8)


// IRQ Number
#define S3C24XX_IRQ(x) (x)
//
#define IRQ_EINT0      S3C24XX_IRQ(0)
#define IRQ_EINT1      S3C24XX_IRQ(1)
#define IRQ_EINT2      S3C24XX_IRQ(2)
#define IRQ_EINT3      S3C24XX_IRQ(3)
#define IRQ_EINT_4TO7  S3C24XX_IRQ(4)
#define IRQ_EINT_8TO23 S3C24XX_IRQ(5)
#define IRQ_RESERVED6  S3C24XX_IRQ(6)
#define IRQ_CAM        S3C24XX_IRQ(6)
#define IRQ_BATT_FLT   S3C24XX_IRQ(7)
#define IRQ_TICK       S3C24XX_IRQ(8)
#define IRQ_WDT	       S3C24XX_IRQ(9)
#define IRQ_TIMER0     S3C24XX_IRQ(10)
#define IRQ_TIMER1     S3C24XX_IRQ(11)
#define IRQ_TIMER2     S3C24XX_IRQ(12)
#define IRQ_TIMER3     S3C24XX_IRQ(13)
#define IRQ_TIMER4     S3C24XX_IRQ(14)
#define IRQ_UART2      S3C24XX_IRQ(15)
#define IRQ_LCD	       S3C24XX_IRQ(16)
#define IRQ_DMA0       S3C24XX_IRQ(17)
#define IRQ_DMA1       S3C24XX_IRQ(18)
#define IRQ_DMA2       S3C24XX_IRQ(19)
#define IRQ_DMA3       S3C24XX_IRQ(20)
#define IRQ_SDI	       S3C24XX_IRQ(21)
#define IRQ_SPI0       S3C24XX_IRQ(22)
#define IRQ_UART1      S3C24XX_IRQ(23)
#define IRQ_RESERVED24 S3C24XX_IRQ(24)
#define IRQ_NFCON      S3C24XX_IRQ(24)
#define IRQ_USBD       S3C24XX_IRQ(25)
#define IRQ_USBH       S3C24XX_IRQ(26)
#define IRQ_IIC	       S3C24XX_IRQ(27)
#define IRQ_UART0      S3C24XX_IRQ(28)
#define IRQ_SPI1       S3C24XX_IRQ(29)
#define IRQ_RTC	       S3C24XX_IRQ(30)
#define IRQ_TC_ADC     S3C24XX_IRQ(31)
//
#define IRQ_EINT4      S3C24XX_IRQ(32)
#define IRQ_EINT5      S3C24XX_IRQ(33)
#define IRQ_EINT6      S3C24XX_IRQ(34)
#define IRQ_EINT7      S3C24XX_IRQ(35)
#define IRQ_EINT8      S3C24XX_IRQ(36)
#define IRQ_EINT9      S3C24XX_IRQ(37)
#define IRQ_EINT10     S3C24XX_IRQ(38)
#define IRQ_EINT11     S3C24XX_IRQ(39)
#define IRQ_EINT12     S3C24XX_IRQ(40)
#define IRQ_EINT13     S3C24XX_IRQ(41)
#define IRQ_EINT14     S3C24XX_IRQ(42)
#define IRQ_EINT15     S3C24XX_IRQ(43)
#define IRQ_EINT16     S3C24XX_IRQ(44)
#define IRQ_EINT17     S3C24XX_IRQ(45)
#define IRQ_EINT18     S3C24XX_IRQ(46)
#define IRQ_EINT19     S3C24XX_IRQ(47)
#define IRQ_EINT20     S3C24XX_IRQ(48)
#define IRQ_EINT21     S3C24XX_IRQ(49)
#define IRQ_EINT22     S3C24XX_IRQ(50)
#define IRQ_EINT23     S3C24XX_IRQ(51)
// LCD
#define IRQ_LCD_FIFO   S3C24XX_IRQ(52)
#define IRQ_LCD_FRAME  S3C24XX_IRQ(53)
// UART
#define IRQ_UART0_RX   S3C24XX_IRQ(54)
#define IRQ_UART0_TX   S3C24XX_IRQ(55)
#define IRQ_UART0_ERR  S3C24XX_IRQ(56)
#define IRQ_UART1_RX   S3C24XX_IRQ(57)
#define IRQ_UART1_TX   S3C24XX_IRQ(58)
#define IRQ_UART1_ERR  S3C24XX_IRQ(59)
#define IRQ_UART2_RX   S3C24XX_IRQ(60)
#define IRQ_UART3_TX   S3C24XX_IRQ(61)
#define IRQ_UART2_ERR  S3C24XX_IRQ(62)
// TC & ADC
#define IRQ_TC         S3C24XX_IRQ(63)
#define IRQ_ADC        S3C24XX_IRQ(64)

#define MAX_IRQ_NUM    (IRQ_ADC + 1)

//
#define S3C2410_EXTINT_LOWLEV	 (0x00)
#define S3C2410_EXTINT_HILEV	 (0x01)
#define S3C2410_EXTINT_FALLEDGE	 (0x02)
#define S3C2410_EXTINT_RISEEDGE	 (0x04)
#define S3C2410_EXTINT_BOTHEDGE	 (0x06)

// Clock and Power Management
#define CLOCK_BASE      0x4c000000
#define LOCKTIME              0x00
#define MPLLCON               0x04
#define UPLLCON               0x08
#define DIVN                  0x14


// LCD
#define S3C24XX_LCD_BASE 0x4d000000
#define LCDCON1                0x00
#define LCDCON2                0x04
#define LCDCON3                0x08
#define LCDCON4                0x0c
#define LCDCON5                0x10
#define LCDSADDR1              0x14
#define LCDSADDR2              0x18
#define LCDSADDR3              0x1c
#define LCDINTPND              0x54
#define LCDSRCPND              0x58
#define LCDINTMSK              0x5c
#define TCONSEL                0x60
//
#define BPP16_TFT    12
#define BPP24_TFT    13


#define HCLOCK           100000000
#define PCLOCK_50M        50000000


// NAND
#define NAND_CTRL_BASE  0x4e000000
#define NF_CONF               0x00

#define NF_CONT               0x04
#define NF_CMMD               0x08
#define NF_ADDR               0x0c
#define NF_DATA               0x10
#define NF_STAT               0x20
#define NF_SBLK               0x38
#define NF_EBLK               0x3c



// UART
#define UART0_BASE      0x50000000
#define UART1_BASE      (UART0_BASE + 0x4000)
#define UART2_BASE      (UART1_BASE + 0x4000)

#define ULCON                 0x00
#define UCON                  0x04
#define UFCON                 0x08
#define UMCON                 0x0c
#define UTRSTAT               0x10
#define UERSTAT               0x14
#define UFSTAT                0x18
#define UMSTAT                0x1c
#define UTX                   0x20
#define URX                   0x24
#define UBRDIV                0x28

//#undef UART_ENABLE_FIFO


// Watchdog
#define WATCHDOG_BASE   0x53000000
#define WTCON                 0x00
#define WTDATA                0x04
#define WTCNT                 0x08


// GPIO
#define GPIO_BASE       0x56000000
//
#define GPF_CON               0x50
//
#define GPG_CON               0x60
#define GPG_DAT               0x64
#define GPG_UP                0x68
//
#define GPH_CON               0x70
#define GPH_DAT               0x74
#define GPH_UP                0x78
//...
#define EXTINT0               0x88
#define EXTINT1               0x8c
#define EXTINT2               0x90
//...
#define EINTMASK              0xa4
#define EINTPEND              0xa8


// RTC
#define RTC_BASE        0x57000040
#define RTCCON                0x00
#define RTCCNT                0x04

#define PWM_BASE        0x51000000
#define TCFG0				  0x00
#define TCFG1				  0x04
#define TCON				  0x08
#define TCNTB(n)			  (0x0c * (n + 1))
#define TCMPB(n)			  (0x10 + 0xc * n)
#define TCNTO(n)			  (0x14 + 0xc * n)

#define S3C24XX_GPBCON   0x56000010
#define S3C24XX_GPBDAT   0x56000014
#define S3C24XX_GPBUP    0x56000018

#define S3C24XX_GPCCON   0x56000020
#define S3C24XX_GPCDAT   0x56000024
#define S3C24XX_GPCUP    0x56000028

#define S3C24XX_GPDCON   0x56000030
#define S3C24XX_GPDDAT   0x56000034
#define S3C24XX_GPDUP    0x56000038


#endif
