// ROM:
#define ROM_BASE                 (0x00000000)

// XIP:
#define XIP_BASE                 (0x10000000)
#define XIP_NOALLOC_BASE         (0x11000000)
#define XIP_NOCACHE_BASE         (0x12000000)
#define XIP_NOCACHE_NOALLOC_BASE (0x13000000)
#define XIP_CTRL_BASE            (0x14000000)
#define XIP_SRAM_BASE            (0x15000000)
#define XIP_SRAM_END             (0x15004000)
#define XIP_SSI_BASE             (0x18000000)

// SRAM. SRAM0-3 striped:
#define SRAM_BASE                (0x20000000)
#define SRAM_STRIPED_BASE        (0x20000000)
#define SRAM_STRIPED_END         (0x20040000)

// SRAM 4-5 are always non-striped:
#define SRAM4_BASE               (0x20040000)
#define SRAM5_BASE               (0x20041000)
#define SRAM_END                 (0x20042000)

// Non-striped aliases of SRAM0-3:
#define SRAM0_BASE               (0x21000000)
#define SRAM1_BASE               (0x21010000)
#define SRAM2_BASE               (0x21020000)
#define SRAM3_BASE               (0x21030000)

// APB Peripherals:
#define SYSINFO_BASE             (0x40000000)
#define SYSCFG_BASE              (0x40004000)
#define CLOCKS_BASE              (0x40008000)
#define RESETS_BASE              (0x4000c000)
#define PSM_BASE                 (0x40010000)
#define IO_BANK0_BASE            (0x40014000)
#define IO_QSPI_BASE             (0x40018000)
#define PADS_BANK0_BASE          (0x4001c000)
#define PADS_QSPI_BASE           (0x40020000)
#define XOSC_BASE                (0x40024000)
#define PLL_SYS_BASE             (0x40028000)
#define PLL_USB_BASE             (0x4002c000)
#define BUSCTRL_BASE             (0x40030000)
#define UART0_BASE               (0x40034000)
#define UART1_BASE               (0x40038000)
#define SPI0_BASE                (0x4003c000)
#define SPI1_BASE                (0x40040000)
#define I2C0_BASE                (0x40044000)
#define I2C1_BASE                (0x40048000)
#define ADC_BASE                 (0x4004c000)
#define PWM_BASE                 (0x40050000)
#define TIMER_BASE               (0x40054000)
#define WATCHDOG_BASE            (0x40058000)
#define RTC_BASE                 (0x4005c000)
#define ROSC_BASE                (0x40060000)
#define VREG_AND_CHIP_RESET_BASE (0x40064000)
#define TBMAN_BASE               (0x4006c000)

// AHB-Lite peripherals:
#define DMA_BASE                 (0x50000000)

// USB has a DPRAM at its base followed by registers:
#define USBCTRL_BASE             (0x50100000)
#define USBCTRL_DPRAM_BASE       (0x50100000)
#define USBCTRL_REGS_BASE        (0x50110000)

// Remaining AHB-Lite peripherals:
#define PIO0_BASE                (0x50200000)
#define PIO1_BASE                (0x50300000)
#define XIP_AUX_BASE             (0x50400000)

// IOPORT Peripherals:
#define SIO_BASE                 (0xd0000000)

// Cortex-M0+ Internal Peripherals:
#define PPB_BASE                 (0xe0000000)
// Registers
//0xe010 SYST_CSR SysTick Control and Status Register
//0xe014 SYST_RVR SysTick Reload Value Register
//0xe018 SYST_CVR SysTick Current Value Register
//0xe01c SYST_CALIB SysTick Calibration Value Register
//0xe100 NVIC_ISER Interrupt Set-Enable Register
//0xe180 NVIC_ICER Interrupt Clear-Enable Register
//0xe200 NVIC_ISPR Interrupt Set-Pending Register
//0xe280 NVIC_ICPR Interrupt Clear-Pending Register
//0xe400 NVIC_IPR0 Interrupt Priority Register 0
//0xe404 NVIC_IPR1 Interrupt Priority Register 1
//0xe408 NVIC_IPR2 Interrupt Priority Register 2
//0xe40c NVIC_IPR3 Interrupt Priority Register 3
//0xe410 NVIC_IPR4 Interrupt Priority Register 4
//0xe414 NVIC_IPR5 Interrupt Priority Register 5
//0xe418 NVIC_IPR6 Interrupt Priority Register 6
//0xe41c NVIC_IPR7 Interrupt Priority Register 7
//0xed00 CPUID CPUID Base Register
//0xed04 ICSR Interrupt Control and State Register
//0xed08 VTOR Vector Table Offset Register
//0xed0c AIRCR Application Interrupt and Reset Control Register
//0xed10 SCR System Control Register
//0xed14 CCR Configuration and Control Register
//0xed1c SHPR2 System Handler Priority Register 2
//0xed20 SHPR3 System Handler Priority Register 3
//0xed24 SHCSR System Handler Control and State Register
//0xed90 MPU_TYPE MPU Type Register
//0xed94 MPU_CTRL MPU Control Register
//0xed98 MPU_RNR MPU Region Number Register
//0xed9c MPU_RBAR MPU Region Base Address Register
//0xeda0 MPU_RASR MPU Region Attribute and Size Register
