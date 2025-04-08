#ifndef SYSDEF_HPP
#define SYSDEF_HPP

/***
 * ROM:
 ***/
#define ROM_BASE                     (0x00000000)

/***
 * XIP:
 ***/
#define XIP_BASE                     (0x10000000)
#define XIP_NOALLOC_BASE             (0x11000000)
#define XIP_NOCACHE_BASE             (0x12000000)
#define XIP_NOCACHE_NOALLOC_BASE     (0x13000000)
#define XIP_CTRL_BASE                (0x14000000)
#define XIP_SRAM_BASE                (0x15000000)
#define XIP_SRAM_END                 (0x15004000)
#define XIP_SSI_BASE                 (0x18000000)

/***
 * SRAM:
 ***/
#define SRAM_BASE                    (0x20000000)
#define SRAM_SIZE                    (256*1024)             // PicoのSRAMは256K
#define INITIAL_SP                   (SRAM_BASE+SRAM_SIZE)  // 初期スタックポインタは最後尾領域を使う

/***
 * APB Peripherals:
 ***/
#define SYSINFO_BASE                 (0x40000000)
#define SYSCFG_BASE                  (0x40004000)
// CLOCK Registers
#define CLOCKS_BASE                  (0x40008000)
#if 1
#define CLK_TYPE_GPOUT0              (0x00)
#define CLK_TYPE_GPOUT1              (0x0C)
#define CLK_TYPE_GPOUT2              (0x18)
#define CLK_TYPE_GPOUT3              (0x24)
#define CLK_TYPE_REF                 (0x30)
#define CLK_TYPE_SYS                 (0x3C)
#define CLK_TYPE_PERI                (0x48)
#define CLK_TYPE_USB                 (0x54)
#define CLK_TYPE_ADC                 (0x60)
#define CLK_TYPE_RTC                 (0x6C)

#define CLK_CTRL_OFFSET              (0x00)
#define CLK_SYS_CTRL_ENABLE_BITS     (0x00000800)
#define CLK_SYS_CTRL_AUXSRC_BITS     (0x000000E0)
#define CLK_SYS_CTRL_AUXSRC_MSB      (7)
#define CLK_SYS_CTRL_AUXSRC_LSB      (5)
#define CLK_REF_CTRL_SRC_BITS        (0x00000003)
#define CLK_REF_CTRL_SRC_MSB         (1)
#define CLK_REF_CTRL_SRC_LSB         (0)
#define CLK_DIV_OFFSET               (0x04)
#define CLK_SELECTED_OFFSET          (0x08)
#else
#define CLK_GPOUT0_CTRL              (CLOCKS_BASE+0x00)
#define CLK_GPOUT0_DIV               (CLOCKS_BASE+0x04)
#define CLK_GPOUT0_SELECTED          (CLOCKS_BASE+0x08)

#define CLK_GPOUT1_CTRL              (CLOCKS_BASE+0x0C)
#define CLK_GPOUT1_DIV               (CLOCKS_BASE+0x10)
#define CLK_GPOUT1_SELECTED          (CLOCKS_BASE+0x14)

#define CLK_GPOUT2_CTRL              (CLOCKS_BASE+0x18)
#define CLK_GPOUT2_DIV               (CLOCKS_BASE+0x1C)
#define CLK_GPOUT2_SELECTED          (CLOCKS_BASE+0x20)

#define CLK_GPOUT3_CTRL              (CLOCKS_BASE+0x24)
#define CLK_GPOUT3_DIV               (CLOCKS_BASE+0x28)
#define CLK_GPOUT3_SELECTED          (CLOCKS_BASE+0x2C)

#define CLK_REF_CTRL                 (CLOCKS_BASE+0x30)
#define CLK_REF_DIV                  (CLOCKS_BASE+0x34)
#define CLK_REF_SELECTED             (CLOCKS_BASE+0x38)

#define CLK_SYS_CTRL                 (CLOCKS_BASE+0x3C)
#define CLK_SYS_DIV                  (CLOCKS_BASE+0x40)
#define CLK_SYS_SELECTED             (CLOCKS_BASE+0x44)

#define CLK_PERI_CTRL                (CLOCKS_BASE+0x48)
#define CLK_PERI_SELECTED            (CLOCKS_BASE+0x50)

#define CLK_USB_CTRL                 (CLOCKS_BASE+0x54)
#define CLK_USB_DIV                  (CLOCKS_BASE+0x58)
#define CLK_USB_SELECTED             (CLOCKS_BASE+0x5C)

#define CLK_ADC_CTRL                 (CLOCKS_BASE+0x60)
#define CLK_ADC_DIV                  (CLOCKS_BASE+0x64)
#define CLK_ADC_SELECTED             (CLOCKS_BASE+0x68)

#define CLK_RTC_CTRL                 (CLOCKS_BASE+0x6C)
#define CLK_RTC_DIV                  (CLOCKS_BASE+0x70)
#define CLK_RTC_SELECTED             (CLOCKS_BASE+0x74)
#endif

#define CLK_SYS_RESUS_CTRL           (CLOCKS_BASE+0x78)
#define CLK_SYS_RESUS_STATUS         (CLOCKS_BASE+0x7C)
#define CLK_FC0_REF_KHZ              (CLOCKS_BASE+0x80)
#define CLK_FC0_MIN_KHZ              (CLOCKS_BASE+0x84)
#define CLK_FC0_MAX_KHZ              (CLOCKS_BASE+0x88)
#define CLK_FC0_DELAY                (CLOCKS_BASE+0x8C)
#define CLK_FC0_INTERVAL             (CLOCKS_BASE+0x90)
#define CLK_FC0_SRC                  (CLOCKS_BASE+0x94)
#define CLK_FC0_STATUS               (CLOCKS_BASE+0x98)
#define CLK_FC0_RESULT               (CLOCKS_BASE+0x9C)
#define CLK_WAKE_EN0                 (CLOCKS_BASE+0xA0)
#define CLK_WAKE_EN1                 (CLOCKS_BASE+0xA4)
#define CLK_SLEEP_EN0                (CLOCKS_BASE+0xA8)
#define CLK_SLEEP_EN1                (CLOCKS_BASE+0xAC)
#define CLK_ENABLED0                 (CLOCKS_BASE+0xB0)
#define CLK_ENABLED1                 (CLOCKS_BASE+0xB4)
#define CLK_INTR                     (CLOCKS_BASE+0xB8)
#define CLK_INTE                     (CLOCKS_BASE+0xBC)
#define CLK_INTF                     (CLOCKS_BASE+0xC0)
#define CLK_INTS                     (CLOCKS_BASE+0xC4)

#define RESETS_BASE                  (0x4000C000)
#define RESETS_RESET                 (RESETS_BASE+0x0)
#define RESETS_RESET_BIT_PLL_SYS     (1<<12)
#define RESETS_RESET_BIT_PLL_USB     (1<<13)
#define RESETS_WDSEL                 (RESETS_BASE+0x4)
#define RESETS_RESET_DONE            (RESETS_BASE+0x8)
#define RESETS_BIT_USBCTRL           (1<<24)
#define RESETS_BIT_UART1             (1<<23)
#define RESETS_BIT_UART0             (1<<22)
#define RESETS_BIT_TIMER             (1<<21)
#define RESETS_BIT_TBMAN             (1<<20)
#define RESETS_BIT_SYSINFO           (1<<19)
#define RESETS_BIT_SYSCFG            (1<<18)
#define RESETS_BIT_SPI1              (1<<17)
#define RESETS_BIT_SPI0              (1<<16)
#define RESETS_BIT_RTC               (1<<15)
#define RESETS_BIT_PWM               (1<<14)
#define RESETS_BIT_PLL_USB           (1<<13)
#define RESETS_BIT_PLL_SYS           (1<<12)
#define RESETS_BIT_PIO1              (1<<11)
#define RESETS_BIT_PIO0              (1<<10)
#define RESETS_BIT_PADS_QSPI         (1<<9)
#define RESETS_BIT_PADS_BANK0        (1<<8)
#define RESETS_BIT_JTAG              (1<<7)
#define RESETS_BIT_IO_QSPI           (1<<6)
#define RESETS_BIT_IO_BANK0          (1<<5)
#define RESETS_BIT_I2C1              (1<<4)
#define RESETS_BIT_I2C0              (1<<3)
#define RESETS_BIT_DMA               (1<<2)
#define RESETS_BIT_BUSCTRL           (1<<1)
#define RESETS_BIT_ADC               (1<<0)

#define PSM_BASE                     (0x40010000)
#define IO_BANK0_BASE                (0x40014000)
#define IO_QSPI_BASE                 (0x40018000)
#define PADS_BANK0_BASE              (0x4001C000)
#define PADS_QSPI_BASE               (0x40020000)

/***
 * PLL Definitions
 ***/
// XOSC Registers
#define XOSC_BASE                    (0x40024000)
#define XOSC_CTRL                    (XOSC_BASE+0x00)
#define XOSC_CTRL_ENABLE             (0xFAB)
#define XOSC_CTRL_DISABLE            (0xD1E)
#define XOSC_CTRL_ENABLE_MSB         (23)
#define XOSC_CTRL_ENABLE_LSB         (12)
#define XOSC_CTRL_FREQ_RQNGE_1_15MHZ (0xAA0)
#define XOSC_CTRL_FREQ_RQNGE_MSB     (11)
#define XOSC_CTRL_FREQ_RQNGE_LSB     (0)
#define XOSC_STATUS                  (XOSC_BASE+0x04)
#define XOSC_STATUS_STABLE_BITS      (0x80000000)
#define XOSC_STATUS_STABLE_MSB       (31)
#define XOSC_STATUS_STABLE_LSB       (31)
#define XOSC_DORMANT                 (XOSC_BASE+0x08)
#define XOSC_STARTUP                 (XOSC_BASE+0x0C)
#define XOSC_COUNT                   (XOSC_BASE+0x1C)

#define PLL_SYS_BASE                 (0x40028000)
#define PLL_USB_BASE                 (0x4002C000)
#define PLL_CS_OFFSET                (0x0)
#define PLL_CS_BIT_LOCK              (1<<31)
#define PLL_PWR_OFFSET               (0x4)
#define PLL_PWR_BIT_VCOPD            (1<<5)
#define PLL_PWR_BIT_POSTDIVPD        (1<<3)
#define PLL_PWR_BIT_DSMPD            (1<<2)
#define PLL_PWR_BIT_PD               (1<<0)
#define PLL_FBDIV_INT_OFFSET         (0x8)
#define PLL_PRIM_OFFSET              (0xC)

#define PLL_PRIM_POSTDIV1_LSB        (16)
#define PLL_PRIM_POSTDIV2_LSB        (12)

#define BUSCTRL_BASE                 (0x40030000)
#define UART0_BASE                   (0x40034000)
#define UART1_BASE                   (0x40038000)
#define SPI0_BASE                    (0x4003C000)
#define SPI1_BASE                    (0x40040000)
#define I2C0_BASE                    (0x40044000)
#define I2C1_BASE                    (0x40048000)
#define ADC_BASE                     (0x4004C000)
#define PWM_BASE                     (0x40050000)
#define TIMER_BASE                   (0x40054000)
#define WATCHDOG_BASE                (0x40058000)
#define RTC_BASE                     (0x4005C000)
#define ROSC_BASE                    (0x40060000)
#define VREG_AND_CHIP_RESET_BASE     (0x40064000)
#define TBMAN_BASE                   (0x4006C000)

/***
 * AHB-Lite peripherals:
 ***/
#define DMA_BASE                     (0x50000000)

/***
 * USB has a DPRAM at its base followed by registers:
 ***/
#define USBCTRL_BASE                 (0x50100000)
#define USBCTRL_DPRAM_BASE           (0x50100000)
#define USBCTRL_REGS_BASE            (0x50110000)

/***
 * Remaining AHB-Lite peripherals:
 ***/
#define PIO0_BASE                    (0x50200000)
#define PIO1_BASE                    (0x50300000)
#define XIP_AUX_BASE                 (0x50400000)

/***
 * IOPORT Peripherals:
 ***/
#define SIO_BASE                     (0xD0000000)
#define SIO_CPUID                    (SIO_BASE+0x000) //Processor core identifier
#define GPIO_IN                      (SIO_BASE+0x004) //Input value for GPIO pins
#define GPIO_HI_IN                   (SIO_BASE+0x008) //Input value for QSPI pins
#define GPIO_OUT                     (SIO_BASE+0x010) //GPIO output value
#define GPIO_OUT_SET                 (SIO_BASE+0x014) //GPIO output value set
#define GPIO_OUT_CLR                 (SIO_BASE+0x018) //GPIO output value clear
#define GPIO_OUT_XOR                 (SIO_BASE+0x01c) //GPIO output value XOR
#define GPIO_OE                      (SIO_BASE+0x020) //GPIO output enable
#define GPIO_OE_SET                  (SIO_BASE+0x024) //GPIO output enable set
#define GPIO_OE_CLR                  (SIO_BASE+0x028) //GPIO output enable clear
#define GPIO_OE_XOR                  (SIO_BASE+0x02c) //GPIO output enable XOR
#define GPIO_HI_OUT                  (SIO_BASE+0x030) //QSPI output value
#define GPIO_HI_OUT_SET              (SIO_BASE+0x034) //QSPI output value set
#define GPIO_HI_OUT_CLR              (SIO_BASE+0x038) //QSPI output value clear
#define GPIO_HI_OUT_XOR              (SIO_BASE+0x03c) //QSPI output value XOR
#define GPIO_HI_OE                   (SIO_BASE+0x040) //QSPI output enable
#define GPIO_HI_OE_SET               (SIO_BASE+0x044) //QSPI output enable set
#define GPIO_HI_OE_CLR               (SIO_BASE+0x048) //QSPI output enable clear
#define GPIO_HI_OE_XOR               (SIO_BASE+0x04c) //QSPI output enable XOR

#define GPIO_PORT_LED                (1<<25)          // RasberyPi pico on board LED port

/***
 * Cortex-M0+ Internal Peripherals:
 ***/
#define PPB_BASE                     (0xE0000000)
#define SYST_CSR                     (PPB_BASE+0xE010) // SysTick Control and Status Register
#define SYST_CSR_COUTFLAG            (1<<16)
#define SYST_CSR_CLKSOURCE           (1<<2)
#define SYST_CSR_TICKINT             (1<<1)
#define SYST_CSR_ENABLE              (1<<0)
#define SYST_RVR                     (PPB_BASE+0xE014) // SysTick Reload Value Register
#define SYST_CVR                     (PPB_BASE+0xE018) // SysTick Current Value Register
#define SYST_CALIB                   (PPB_BASE+0xE01C) // SysTick Calibration Value Register
#define NVIC_ISER                    (PPB_BASE+0xE100) // Interrupt Set-Enable Register
#define NVIC_ICER                    (PPB_BASE+0xE180) // Interrupt Clear-Enable Register
#define NVIC_ISPR                    (PPB_BASE+0xE200) // Interrupt Set-Pending Register
#define NVIC_ICPR                    (PPB_BASE+0xE280) // Interrupt Clear-Pending Register
#define NVIC_IPR0                    (PPB_BASE+0xE400) // Interrupt Priority Register 0
#define NVIC_IPR1                    (PPB_BASE+0xE404) // Interrupt Priority Register 1
#define NVIC_IPR2                    (PPB_BASE+0xE408) // Interrupt Priority Register 2
#define NVIC_IPR3                    (PPB_BASE+0xE40C) // Interrupt Priority Register 3
#define NVIC_IPR4                    (PPB_BASE+0xE410) // Interrupt Priority Register 4
#define NVIC_IPR5                    (PPB_BASE+0xE414) // Interrupt Priority Register 5
#define NVIC_IPR6                    (PPB_BASE+0xE418) // Interrupt Priority Register 6
#define NVIC_IPR7                    (PPB_BASE+0xE41C) // Interrupt Priority Register 7
#define CPUID                        (PPB_BASE+0xED00) // CPUID Base Register
#define ICSR                         (PPB_BASE+0xED04) // Interrupt Control and State Register
#define VTOR                         (PPB_BASE+0xED08) // Vector Table Offset Register
#define AIRCR                        (PPB_BASE+0xED0C) // Application Interrupt and Reset Control Register
#define SCR                          (PPB_BASE+0xED10) // System Control Register
#define CCR                          (PPB_BASE+0xED14) // Configuration and Control Register
#define SHPR2                        (PPB_BASE+0xED1C) // System Handler Priority Register 2
#define SHPR3                        (PPB_BASE+0xED20) // System Handler Priority Register 3
#define SHCSR                        (PPB_BASE+0xED24) // System Handler Control and State Register
#define MPU_TYPE                     (PPB_BASE+0xED90) // MPU Type Register
#define MPU_CTRL                     (PPB_BASE+0xED94) // MPU Control Register
#define MPU_RNR                      (PPB_BASE+0xED98) // MPU Region Number Register
#define MPU_RBAR                     (PPB_BASE+0xED9C) // MPU Region Base Address Register
#define MPU_RASR                     (PPB_BASE+0xEDA0) // MPU Region Attribute and Size Register

/***
 * Unit
 ***/
#define KHz                          (1000)
#define MHz                          (1000*KHz)

#define XOSC_HZ                      (12000000u)

#define SYS_HZ                       (125*MHz)
#define TIMER_PERIOD_MS              (1)
#endif
