/************************************************************************
	STM32 446 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 07062022 inic
Comment: 
	Virtual Image STM32-446, mapping.
************************************************************************/
#ifndef _STM32446MAPPING_H_
	#define _STM32446MAPPING_H_
/*
*** Header Files
*/

#include <inttypes.h>

/*
*** Define and Macros From stm32 lib
*/

#define PERIPH_BASE 0x40000000UL
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x10000000UL)

/*
*** Global Variables
*/

/***** STM32 F446 START *****/

// General-purpose Registers (GPR)
typedef struct STM32446Gpr{
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
	uint32_t r12;
}STM32446Gpr;

// Processor Core Registers (PCR)
typedef struct STM32446Pcr{
	uint32_t sp;
	uint32_t lr;
	uint32_t pc;
	uint32_t psr;
	uint32_t primask;
	uint32_t faultmask;
	uint32_t basepri;
	uint32_t control;
}STM32446Pcr;

// Memory protection unit (MPU)
typedef struct STM32446Mpu{
	uint32_t typer;
	uint32_t ctrl;
	uint32_t rnr;
	uint32_t rbar;
	uint32_t rasr;
	uint32_t rbara1;
	uint32_t rasra1;
	uint32_t rbara2;
	uint32_t rasra2;
	uint32_t rbara3;
	uint32_t rasra3;
}STM32446Mpu;

/**
// Nested Vectored Interrupt Controller (NVIC)
typedef struct STM32446Nvic{ // 0xE000E100
	uint32_t iser[8]; // 0xE000E100 - 0xE000E11F
	uint32_t fill1[23]; // ((0XE000E180 - 0xE000E11F) / 4)  - 1
	uint32_t icer[8]; // 0XE000E180 - 0xE000E19F
	uint32_t fill2[23]; // ((0XE000E200 - 0xE000E19F) / 4)  - 1
	uint32_t ispr[8]; // 0XE000E200 - 0xE000E21F
	uint32_t fill3[23]; // ((0XE000E280 - 0xE000E21F) / 4)  - 1
	uint32_t icpr[8]; // 0XE000E280 - 0xE000E29F
	uint32_t fill4[23]; // ((0XE000E300 - 0xE000E29F) / 4)  - 1
	uint32_t iabr[8]; // 0xE000E300 - 0xE000E31F
	uint32_t fill5[55]; // ((0XE000E400 - 0xE000E31F) / 4)  - 1
	uint32_t ipr[60]; // 0xE000E400 - 0xE000E4EF
	uint32_t fill6[643]; // ((0xE000EF00 - 0xE000E4EF) / 4)  - 1
	uint32_t stir; // 0xE000EF00
}STM32446Nvic;
**/

/**
// System Control Block (SCB)
typedef struct STM32446Scb{ // 0xE000 E008
	uint32_t actrl; // 0xE000E008
	uint32_t fill1[829]; // ((0xE000ED00 - 0xE000E008) / 4)  - 1
	uint32_t cpuid; // 0xE000ED00
	uint32_t icsr; // 0xE000ED04
	uint32_t vtor; // 0xE000ED08
	uint32_t aircr; // 0xE000ED0C
	uint32_t scr; // 0xE000ED10
	uint32_t ccr; // 0xE000ED14
	uint32_t shpr1; // 0xE000ED18
	uint32_t shpr2; // 0xE000ED1C
	uint32_t shpr3; // 0xE000ED20
	uint32_t shcsr; // 0xE000ED24
	uint32_t cfsr; // 0xE000ED28
	uint32_t hfsr; // 0xE000ED2C
	uint32_t fill2; // ((0xE000ED34 - 0xE000ED2C) / 4)  - 1
	uint32_t mmar; // 0xE000ED34
	uint32_t bfar; // 0xE000ED38
	uint32_t afsr; // 0xE000ED3C
}STM32446Scb;
**/

/**
// SysTick Timer (STK)
typedef struct STM32446Stk{ // 0xE000 E010
	uint32_t ctrl; // 0xE000E010
	uint32_t load; // 0xE000E014
	uint32_t val; // 0xE000E018
	uint32_t calib; // 0xE000E01C
}STM32446Stk;
**/

/**
// Floating Point Unit (FPU)
typedef struct STM32446Fpu{ // 0xE000ED88
	uint32_t cpacr; // 0xE000ED88
	uint32_t fill[106]; // ((0xE000EF34 - 0xE000ED88) / 4)  - 1
	uint32_t fpccr; // 0xE000EF34
	uint32_t fpcar; // 0xE000EF38
	uint32_t fpdscr; // 0xE000EF3C
}STM32446Fpu;
**/

/************/

// Embedded Flash memory interface 0x4002 3C00 - 0x4002 3FFF pg65
typedef struct STM32446Flash{ // 0x4002 3C00
	uint32_t acr;
	uint32_t keyr; // KEY1 = 0x45670123, KEY2 = 0xCDEF89AB to access FLASH_CR
	uint32_t optkeyr;
	uint32_t sr;
	uint32_t cr;
	uint32_t optcr; // Reset value: 0x0FFF AAED
	uint32_t optcr1;
}STM32446Flash;

// CRC calculation unit 0x4002 3000 - 0x4002 33FF pg68
typedef struct STM32446Crc{ // 0x4002 3000
	uint32_t dr;
	uint32_t idr;
	uint32_t cr;
}STM32446Crc;

// Power controller (PWR) 0x4000 7000 - 0x4000 73FF pg86
typedef struct STM32446Pwr{ // 0x4000 7000
	uint32_t cr;
	uint32_t csr;
}STM32446Pwr;

// Reset and clock control (RCC) 0x4002 3800 - 0x4002 3BFF pg133
typedef struct STM32446Rcc{ // 0x4002 3800
	uint32_t cr;
	uint32_t pllcfgr;
	uint32_t cfgr;
	uint32_t cir;
	uint32_t ahb1rstr;
	uint32_t ahb2rstr;
	uint32_t ahb3rstr;
	uint32_t fill1;
	uint32_t apb1rstr;
	uint32_t apb2rstr;
	uint32_t fill2[2];
	uint32_t ahb1enr;
	uint32_t ahb2enr;
	uint32_t ahb3enr;
	uint32_t fill3;
	uint32_t apb1enr;
	uint32_t apb2enr;
	uint32_t fill4[2];
	uint32_t ahb1lpenr;
	uint32_t ahb2lpenr;
	uint32_t ahb3lpenr;
	uint32_t fill5;
	uint32_t apb1lpenr;
	uint32_t apb2lpenr;
	uint32_t fill6[2];
	uint32_t bdcr;
	uint32_t csr;
	uint32_t fill7[2];
	uint32_t sscgr;
	uint32_t plli2scfgr;
	uint32_t fill8;
	uint32_t dckcfgr;
}STM32446Rcc;

// System configuration controller (SYSCFG) 0x4001 3800 - 0x4001 3BFF pg141
typedef struct STM32446Syscfg{ // 0x4001 3800
	uint32_t memrmp;
	uint32_t pmc;
	uint32_t exticr1;
	uint32_t exticr2;
	uint32_t exticr3;
	uint32_t exticr4;
	uint32_t fill[2];
	uint32_t cmpcr;
}STM32446SysCfg;

// General-purpose I/Os (GPIOA) 0x4002 0000 - 0x4002 03FF pg160
typedef struct STM32446GpioA{ // 0x4002 0000
	uint32_t moder;
	uint32_t otyper;
	uint32_t ospeedr;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
	uint32_t lckr;
	uint32_t afrl;
	uint32_t ofrh;
}STM32446GpioA;

// General-purpose I/Os (GPIOB) 0x4002 0400 - 0x4002 07FF pg160
typedef struct STM32446GpioB{ // 0x4002 0400
	uint32_t moder;
	uint32_t otyper;
	uint32_t ospeedr;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
	uint32_t lckr;
	uint32_t afrl;
	uint32_t ofrh;
}STM32446GpioB;

// General-purpose I/Os (GPIOC) 0x4002 0800 - 0x4002 0BFF pg160
typedef struct STM32446GpioC{ // 0x4002 0800
	uint32_t moder;
	uint32_t otyper;
	uint32_t ospeedr;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
	uint32_t lckr;
	uint32_t afrl;
	uint32_t ofrh;
}STM32446GpioC;

// General-purpose I/Os (GPIOD) 0x4002 0C00 - 0x4002 0FFF pg160
typedef struct STM32446GpioD{ // 0x4002 0C00
	uint32_t moder;
	uint32_t otyper;
	uint32_t ospeedr;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
	uint32_t lckr;
	uint32_t afrl;
	uint32_t ofrh;
}STM32446GpioD;

// General-purpose I/Os (GPIOE) 0x4002 1000 - 0x4002 13FF pg160
typedef struct STM32446GpioE{ // 0x4002 1000
	uint32_t moder;
	uint32_t otyper;
	uint32_t ospeedr;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
	uint32_t lckr;
	uint32_t afrl;
	uint32_t ofrh;
}STM32446GpioE;

// General-purpose I/Os (GPIOH) 0x4002 1C00 - 0x4002 pg160
typedef struct STM32446GpioH{ // 0x4002 1C00
	uint32_t moder;
	uint32_t otyper;
	uint32_t ospeedr;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
	uint32_t lckr;
	uint32_t afrl;
	uint32_t ofrh;
}STM32446GpioH;

// DMA Stream
typedef struct STM32446Dmastream{
	uint32_t scr;
	uint32_t sndtr;
	uint32_t spar;
	uint32_t sm0ar;
	uint32_t sm1ar;
	uint32_t sfcr;
}STM32446Dmastream;

// DMA1 controller (DMA1) 0x4002 6000 - 0x4002 63FF pg194
typedef struct STM32446Dma1{ // 0x4002 6000
	uint32_t lisr;
	uint32_t hisr;
	uint32_t lifcr;
	uint32_t hifcr;
	STM32446Dmastream stream[8];
}STM32446Dma1;

// DMA2 controller (DMA2)  0x4002 6400 - 0x4002 67FF pg194
typedef struct STM32446Dma2{ // 0x4002 6400
	uint32_t lisr;
	uint32_t hisr;
	uint32_t lifcr;
	uint32_t hifcr;
	STM32446Dmastream stream[8];
}STM32446Dma2;

// Interrupts and events (EXTI) 0x4001 3C00 - 0x4001 3FFF pg208
typedef struct STM32446Exti{ // 0x4001 3C00
	uint32_t imr;
	uint32_t emr;
	uint32_t rtsr;
	uint32_t ftsr;
	uint32_t swier;
	uint32_t pr;
}STM32446Exti;

// Analog-to-digital converter (ADC1) 0x4001 2000 - 0x4001 23FF pg236
typedef struct STM32446Adc1{ // 0x4001 2000
	uint32_t sr;
	uint32_t cr1;
	uint32_t cr2;
	uint32_t smpr1;
	uint32_t smpr2;
	uint32_t jofr1;
	uint32_t jofr2;
	uint32_t jofr3;
	uint32_t jofr4;
	uint32_t htr;
	uint32_t ltr;
	uint32_t sqr1;
	uint32_t sqr2;
	uint32_t sqr3;
	uint32_t jsqr;
	uint32_t jdr1;
	uint32_t jdr2;
	uint32_t jdr3;
	uint32_t jdr4;
	uint32_t dr; // 0x4C
	uint32_t fill[172]; // ((0x300 - 0x04C) / 4)  - 1
	// Common
	uint32_t csr; // 0x300
	uint32_t ccr;
	uint32_t cdr;
}STM32446Adc1;

// Advanced-control timer (TIM1) 0x4001 0000 - 0x4001 03FF pg304
typedef struct STM32446Tim1{ // 0x4001 0000
	uint32_t cr1;
	uint32_t cr2;
	uint32_t smcr;
	uint32_t dier;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t ccmr2;
	uint32_t ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t rcr;
	uint32_t ccr1;
	uint32_t ccr2;
	uint32_t ccr3;
	uint32_t ccr4;
	uint32_t bdtr;
	uint32_t dcr;
	uint32_t dmar;
}STM32446Tim1;

// General-purpose timers (TIM2) 0x4000 0000 - 0x4000 03FF pg364
typedef struct STM32446Tim2{ // 0x4000 0000
	uint32_t cr1;
	uint32_t cr2;
	uint32_t smcr;
	uint32_t dier;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t ccmr2;
	uint32_t ccer1;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t fill1;
	uint32_t ccr1;
	uint32_t ccr2;
	uint32_t ccr3;
	uint32_t ccr4;
	uint32_t fill2;
	uint32_t dcr;
	uint32_t dmar;
	uint32_t or;
}STM32446Tim2;

// Advanced-control timer (TIM3) 0x4000 0400 - 0x4000 07FF pg364
typedef struct STM32446Tim3{ // 0x4000 0400
	uint32_t cr1;
	uint32_t cr2;
	uint32_t smcr;
	uint32_t dier;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t ccmr2;
	uint32_t ccer1;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t fill1;
	uint32_t ccr1;
	uint32_t ccr2;
	uint32_t ccr3;
	uint32_t ccr4;
	uint32_t fill2;
	uint32_t dcr;
	uint32_t dmar;
}STM32446Tim3;

// Advanced-control timer (TIM4) 0x4000 0800 - 0x4000 0BFF pg364
typedef struct STM32446Tim4{ // 0x4000 0800
	uint32_t cr1;
	uint32_t cr2;
	uint32_t smcr;
	uint32_t dier;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t ccmr2;
	uint32_t ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t fill1;
	uint32_t ccr1;
	uint32_t ccr2;
	uint32_t ccr3;
	uint32_t ccr4;
	uint32_t fill2;
	uint32_t dcr;
	uint32_t dmar;
}STM32446Tim4;

// Advanced-control timer (TIM5) 0x4000 0C00 - 0x4000 0FFF pg364
typedef struct STM32446Tim5{ // 0x4000 0C00
	uint32_t cr1;
	uint32_t cr2;
	uint32_t smcr;
	uint32_t dier;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t ccmr2;
	uint32_t ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t fill1;
	uint32_t ccr1;
	uint32_t ccr2;
	uint32_t ccr3;
	uint32_t ccr4;
	uint32_t fill2;
	uint32_t dcr;
	uint32_t dmar;
	uint32_t or;
}STM32446Tim5;

// Advanced-control timer (TIM9) 0x4001 4000 - 0x4001 43FF pg398
typedef struct STM32446Tim9{ // 0x4001 4000
	uint32_t cr1;
	uint32_t fill1;
	uint32_t smcr;
	uint32_t dier;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t fill2;
	uint32_t ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t fill3;
	uint32_t ccr1;
	uint32_t ccr2;
	uint32_t fill4;
	uint32_t fill5;
	uint32_t fill6;
	uint32_t fill7;
	uint32_t fill8;
	uint32_t fill9;
}STM32446Tim9;

// Advanced-control timer (TIM10) 0x4001 4400 - 0x4001 47FF pg408
typedef struct STM32446Tim10{ // 0x4001 4400
	uint32_t cr1;
	uint32_t fill1;
	uint32_t fill2;
	uint32_t fill3;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t fill4;
	uint32_t ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t fill5;
	uint32_t ccr1;
	uint32_t fill6;
	uint32_t fill7;
	uint32_t fill8;
	uint32_t fill9;
	uint32_t fill10;
	uint32_t fill11;
	uint32_t or;
}STM32446Tim10;

// Advanced-control timer (TIM11) 0x4001 4800 - 0x4001 4BFF pg408
typedef struct STM32446Tim11{ // 0x4001 4800
	uint32_t cr1;
	uint32_t fill1;
	uint32_t fill2;
	uint32_t fill3;
	uint32_t sr;
	uint32_t egr;
	uint32_t ccmr1;
	uint32_t fill4;
	uint32_t ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t fill5;
	uint32_t ccr1;
	uint32_t fill6;
	uint32_t fill7;
	uint32_t fill8;
	uint32_t fill9;
	uint32_t fill10;
	uint32_t fill11;
	uint32_t or;
}STM32446Tim11;

// Independent watchdog (IWDG) 0x4000 3000 - 0x4000 33FF pg837
typedef struct STM32446Iwdg{ // 0x4000 3000
	uint32_t kr;
	uint32_t pr;
	uint32_t rlr;
	uint32_t sr;
}STM32446IWdg;

// Window watchdog (WWDG) 0x4000 2C00 - 0x4000 2FFF pg422
typedef struct STM32446Wwdg{ // 0x4000 2C00
	uint32_t cr;
	uint32_t cfr;
	uint32_t sr;
}STM32446WWdg;

// Real-time clock (RTC) 0x4000 2800 - 0x4000 2BFF pg459
typedef struct STM32446Rtc{ // 0x4000 2800
	uint32_t tr;
	uint32_t dr;
	uint32_t cr;
	uint32_t isr;
	uint32_t prer;
	uint32_t wutr;
	uint32_t calibr;
	uint32_t alrmar;
	uint32_t alrmbr;
	uint32_t wpr;
	uint32_t ssr;
	uint32_t shiftr;
	uint32_t tstr;
	uint32_t tsdr;
	uint32_t tsssr;
	uint32_t calr;
	uint32_t tafcr;
	uint32_t alrmassr;
	uint32_t alrmbssr;
	uint32_t fill;
	uint32_t bkpr[20];
}STM32446Rtc;

// Inter-integrated circuit interface (I2C1) 0x4000 5400 - 0x4000 57FF pg 496
typedef struct STM32446I2c1{ // 0x4000 5400
	uint32_t cr1;
	uint32_t cr2;
	uint32_t oar1;
	uint32_t oar2;
	uint32_t dr;
	uint32_t sr1;
	uint32_t sr2;
	uint32_t ccr;
	uint32_t trise;
	uint32_t fltr;
}STM32446I2c1;

// Inter-integrated circuit interface (I2C2) 0x4000 5800 - 0x4000 5BFF pg 496
typedef struct STM32446I2c2{ // 0x4000 5800
	uint32_t cr1;
	uint32_t cr2;
	uint32_t oar1;
	uint32_t oar2;
	uint32_t dr;
	uint32_t sr1;
	uint32_t sr2;
	uint32_t ccr;
	uint32_t trise;
	uint32_t fltr;
}STM32446I2c2;

// Inter-integrated circuit interface (I2C3)  0x4000 5C00 - 0x4000 5FFF pg 496
typedef struct STM32446I2c3{ // 0x4000 5C00
	uint32_t cr1;
	uint32_t cr2;
	uint32_t oar1;
	uint32_t oar2;
	uint32_t dr;
	uint32_t sr1;
	uint32_t sr2;
	uint32_t ccr;
	uint32_t trise;
	uint32_t fltr;
}STM32446I2c3;

// Universal synchronous asynchronous receiver transmitter (USART1) 0x4001 1000 - 0x4001 13FF pg548
typedef struct STM32446Usart1{ // 0x4001 1000
	uint32_t sr;
	uint32_t dr;
	uint32_t brr;
	uint32_t cr1;
	uint32_t cr2;
	uint32_t cr3;
	uint32_t gtpr;
}STM32446Usart1;

// Universal synchronous asynchronous receiver transmitter (USART2) 0x4000 4400 - 0x4000 47FF pg548
typedef struct STM32446Usart2{ // 0x4000 4400
	uint32_t sr;
	uint32_t dr;
	uint32_t brr;
	uint32_t cr1;
	uint32_t cr2;
	uint32_t cr3;
	uint32_t gtpr;
}STM32446Usart2;

//Universal synchronous asynchronous receiver transmitter (USART6) 0x4001 1400 - 0x4001 17FF pg548
typedef struct STM32446Usart6{ // 0x4001 1400
	uint32_t sr;
	uint32_t dr;
	uint32_t brr;
	uint32_t cr1;
	uint32_t cr2;
	uint32_t cr3;
	uint32_t gtpr;
}STM32446Usart6;

// Serial peripheral interface (SPI1/I2S1) 0x4001 3000 - 0x4001 33FF pg602
typedef struct STM32446Spi1i2s1{ // 0x4001 3000
	uint32_t cr1;
	uint32_t cr2;
	uint32_t sr;
	uint32_t dr;
	uint32_t crcpr;
	uint32_t rxcrcr;
	uint32_t txcrcr;
	uint32_t i2scfgr;
	uint32_t i2spr;
}STM32446Spi1i2s1;

// Inter-integrated circuit interface (I2S2ext)  0x4000 3400 - 0x4000 37FF pg 496
typedef struct STM32446I2s2ext{ // 0x4000 3400
	uint32_t cr1;
	uint32_t cr2;
	uint32_t sr;
	uint32_t dr;
	uint32_t crcpr;
	uint32_t rxcrcr;
	uint32_t txcrcr;
	uint32_t i2scfgr;
	uint32_t i2spr;
}STM32446I2s2ext;

// Serial peripheral interface (SPI2/I2S2) 0x4000 3800 - 0x4000 3BFF pg602
typedef struct STM32446Spi2i2s2{ // 0x4000 3800
	uint32_t cr1;
	uint32_t cr2;
	uint32_t sr;
	uint32_t dr;
	uint32_t crcpr;
	uint32_t rxcrcr;
	uint32_t txcrcr;
	uint32_t i2scfgr;
	uint32_t i2spr;
}STM32446Spi2i2s2;

// Serial peripheral interface (SPI3/I2S3) 0x4000 3C00 - 0x4000 3FFF pg602
typedef struct STM32446Spi3i2s3{ // 0x4000 3C00
	uint32_t cr1;
	uint32_t cr2;
	uint32_t sr;
	uint32_t dr;
	uint32_t crcpr;
	uint32_t rxcrcr;
	uint32_t txcrcr;
	uint32_t i2scfgr;
	uint32_t i2spr;
}STM32446Spi3i2s3;

// Inter-integrated circuit interface (I2S3ext)  0x4000 4000 - 0x4000 43FF pg 496
typedef struct STM32446I2s3ext{ // 0x4000 4000
	uint32_t cr1;
	uint32_t cr2;
	uint32_t sr;
	uint32_t dr;
	uint32_t crcpr;
	uint32_t rxcrcr;
	uint32_t txcrcr;
	uint32_t i2scfgr;
	uint32_t i2spr;
}STM32446I2s3ext;

// Serial peripheral interface (SPI4/I2S4) 0x4001 3400 - 0x4001 37FF pg602
typedef struct STM32446Spi4i2s4{ // 0x4001 3400
	uint32_t cr1;
	uint32_t cr2;
	uint32_t sr;
	uint32_t dr;
	uint32_t crcpr;
	uint32_t rxcrcr;
	uint32_t txcrcr;
	uint32_t i2scfgr;
	uint32_t i2spr;
}STM32446Spi4i2s4;

// Serial peripheral interface (SPI5/I2S5) 0x4001 5000 - 0x4001 53FFF pg602
typedef struct STM32446Spi5i2s5{ // 0x4001 5000
	uint32_t cr1;
	uint32_t cr2;
	uint32_t sr;
	uint32_t dr;
	uint32_t crcpr;
	uint32_t rxcrcr;
	uint32_t txcrcr;
	uint32_t i2scfgr;
	uint32_t i2spr;
}STM32446Spi5i2s5;

// Secure digital input/output interface (SDIO) 0x4001 2C00 - 0x4001 2FFF pg657
typedef struct STM32446Sdio{ // 0x4001 2C00
	uint32_t power;
	uint32_t clkcr;
	uint32_t arg;
	uint32_t cmd;
	uint32_t respcmd;
	uint32_t resp1;
	uint32_t resp2;
	uint32_t resp3;
	uint32_t resp4;
	uint32_t dtimer;
	uint32_t dlen;
	uint32_t dctrl;
	uint32_t dcount;
	uint32_t sta;
	uint32_t icr;
	uint32_t mask;
	uint32_t fill1[2]; // ((ADDRafter - ADDRbefore) / 4)  - 1
	uint32_t fifocnt;
	uint32_t fill2[13]; // ((ADDRafter - ADDRbefore) / 4)  - 1
	uint32_t fifo;
}STM32446SDio;

// USB on-the-go full-speed (OTG_FS) 0x5000 0000 - 0x5003 FFFF pg744

/*
*** @brief USB_OTG_Core_Registers, from stm32 lib
*/

typedef struct
{
  uint32_t GOTGCTL;
  uint32_t GOTGINT;
  uint32_t GAHBCFG;
  uint32_t GUSBCFG;
  uint32_t GRSTCTL;
  uint32_t GINTSTS;
  uint32_t GINTMSK;
  uint32_t GRXSTSR;
  uint32_t GRXSTSP;
  uint32_t GRXFSIZ;
  uint32_t DIEPTXF0_HNPTXFSIZ;
  uint32_t HNPTXSTS;
  uint32_t Reserved30[2];
  uint32_t GCCFG;
  uint32_t CID;
  uint32_t  Reserved40[48];
  uint32_t HPTXFSIZ;
  uint32_t DIEPTXF[0x0F];
} Usb_Otg_Global;

/*
*** @brief USB_OTG_device_Registers
*/

typedef struct 
{
  uint32_t DCFG;
  uint32_t DCTL;
  uint32_t DSTS;
  uint32_t Reserved0C;
  uint32_t DIEPMSK;
  uint32_t DOEPMSK;
  uint32_t DAINT;
  uint32_t DAINTMSK;
  uint32_t  Reserved20;
  uint32_t Reserved9;
  uint32_t DVBUSDIS;
  uint32_t DVBUSPULSE;
  uint32_t DTHRCTL;
  uint32_t DIEPEMPMSK;
  uint32_t DEACHINT;
  uint32_t DEACHMSK;
  uint32_t Reserved40;
  uint32_t DINEP1MSK;
  uint32_t  Reserved44[15];
  uint32_t DOUTEP1MSK;
} Usb_Otg_Device;

/*
*** @brief USB_OTG_IN_Endpoint-Specific_Register
*/

typedef struct 
{
  uint32_t DIEPCTL;
  uint32_t Reserved04;
  uint32_t DIEPINT;
  uint32_t Reserved0C;
  uint32_t DIEPTSIZ;
  uint32_t DIEPDMA;
  uint32_t DTXFSTS;
  uint32_t Reserved18;
} Usb_Otg_INEndpoint;

/*
*** @brief USB_OTG_OUT_Endpoint-Specific_Registers
*/

typedef struct 
{
  uint32_t DOEPCTL;
  uint32_t Reserved04;
  uint32_t DOEPINT;
  uint32_t Reserved0C;
  uint32_t DOEPTSIZ;
  uint32_t DOEPDMA;
  uint32_t Reserved18[2];
} Usb_Otg_OUTEndpoint;

/*
*** @brief USB_OTG_Host_Mode_Register_Structures
*/

typedef struct 
{
  uint32_t HCFG;
  uint32_t HFIR;
  uint32_t HFNUM;
  uint32_t Reserved40C;
  uint32_t HPTXSTS;
  uint32_t HAINT;
  uint32_t HAINTMSK;
} Usb_Otg_Host;

/*
*** @brief USB_OTG_Host_Channel_Specific_Registers
*/

typedef struct
{
  uint32_t HCCHAR;
  uint32_t HCSPLT;
  uint32_t HCINT;
  uint32_t HCINTMSK;
  uint32_t HCTSIZ;
  uint32_t HCDMA;
  uint32_t Reserved[2];
} Usb_Otg_HostChannel;

// Debug support (DBGMCU) pg828
typedef struct STM32446Dbgmcu{ // 0xE004 2000
	uint32_t idcode; // Address: 0xE004 2000
	uint32_t cr; // Address: 0xE004 2004
	uint32_t apb1fz; // Address : 0xE004 2008
	uint32_t apb2fz; // Address: 0xE004 200C
}STM32446DbgMcu;

/************/

// TPIU (trace port interface unit) pg822
typedef struct STM32446Tpiu{ // 0xE004 0004
	uint32_t CurrentPortSize; // 0xE0040004
	uint32_t fill1[58]; // ((0xE00400F0 - 0xE0040004) / 4)  - 1
	uint32_t SelectedPinProtocol; // 0xE00400F0
	uint32_t fill2[131]; // ((0xE0040300 - 0xE00400F0) / 4)  - 1
	uint32_t FormatterAndFlushStatus; // 0xE0040300
	uint32_t FormatterAndFlushControl; // 0xE0040304
}STM32446TPiu;

// Device electronic signature pg830
typedef struct STM32446Deviceid{ // Base address: 0x1FFF 7A10
	uint32_t uid[3];
}STM32446DeviceId;

// Flash size pg837
typedef struct STM32446Flashsize{ // Base address: 0x1FFF 7A22
	uint32_t fsize;
}STM32446FlashSize;

/***** STM32 F446 END *****/

/*
*** STM32446 IMAGE
*/

typedef struct STM32446{
	STM32446Gpr* gpr;
	STM32446Pcr* pcr;
	STM32446Mpu* mpu;
	/************/
	STM32446Flash* flash;
	STM32446Crc* crc;
	STM32446Pwr* pwr;
	STM32446Rcc* rcc;
	STM32446SysCfg* syscfg;
	STM32446GpioA* gpioa;
	STM32446GpioB* gpiob;
	STM32446GpioC* gpioc;
	STM32446GpioD* gpiod;
	STM32446GpioE* gpioe;
	STM32446GpioH* gpioh;
	STM32446Dma1* dma1;
	STM32446Dma2* dma2;
	STM32446Exti* exti;
	STM32446Adc1* adc1;
	STM32446Tim1* tim1;
	STM32446Tim2* tim2;
	STM32446Tim3* tim3;
	STM32446Tim4* tim4;
	STM32446Tim5* tim5;
	STM32446Tim9* tim9;
	STM32446Tim10* tim10;
	STM32446Tim11* tim11;
	STM32446IWdg* iwdg;
	STM32446WWdg* wwdg;
	STM32446Rtc* rtc;
	STM32446I2c1* i2c1;
	STM32446I2c2* i2c2;
	STM32446I2c3* i2c3;
	STM32446Usart1* usart1;
	STM32446Usart2* usart2;
	STM32446Usart6* usart6;
	STM32446Spi1i2s1* spi1i2s1;
	STM32446I2s2ext* i2s2ext;
	STM32446Spi2i2s2* spi2i2s2;
	STM32446Spi3i2s3* spi3i2s3;
	STM32446I2s3ext* i2s3ext;
	STM32446Spi4i2s4* spi4i2s4;
	STM32446Spi5i2s5* spi5i2s5;
	STM32446SDio* sdio;
	Usb_Otg_Global* otg_global;
	Usb_Otg_Device* otg_device;
	Usb_Otg_INEndpoint* otg_inendpoint;
	Usb_Otg_OUTEndpoint* otg_outendpoint;
	Usb_Otg_Host* otg_host;
	Usb_Otg_HostChannel* otg_hostchannel;
	STM32446DbgMcu* dbgmcu;
	/************/
	STM32446TPiu* tpiu;
	STM32446DeviceId* deviceid;
	STM32446FlashSize* flashsize;
}STM32446;
/*
***
*/
STM32446 STM32446enable(void);
#endif
/***EOF***/
/*** COMMENT
***/
