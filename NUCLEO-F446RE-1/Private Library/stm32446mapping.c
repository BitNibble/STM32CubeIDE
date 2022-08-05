/*************************************************************************
	STM32 446 MAPPING
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 07062022 inic
Comment:
   Mapping
*************************************************************************/
#include "stm32446mapping.h"
/*
***
*/
// ADDRESS TABLE
#define STM32446Gpraddr 0x00000000
#define STM32446Pcraddr 0
#define STM32446Mpuaddr 0
// #define STM32446Nvicaddr 0
// #define STM32446Scbaddr 0
// #define STM32446Stkaddr 0
// #define STM32446Fpuaddr 0
/************/
#define STM32446Flashaddr 0x40023C00
#define STM32446Crcaddr 0x40023000
#define STM32446Pwraddr 0x40007000
#define STM32446Rccaddr 0x40023800
#define STM32446SysCfgaddr 0x40013800
#define STM32446GpioAaddr 0x40020000
#define STM32446GpioBaddr 0x40020400
#define STM32446GpioCaddr 0x40020800
#define STM32446GpioDaddr 0x40020C00
#define STM32446GpioEaddr 0x40021000
#define STM32446GpioHaddr 0x40021C00
#define STM32446Dma1addr 0x40026000
#define STM32446Dma2addr 0x40026400
#define STM32446Extiaddr 0x40013C00
#define STM32446Adc1addr 0x40012000
#define STM32446Tim1addr 0x40010000
#define STM32446Tim2addr 0x40000000
#define STM32446Tim3addr 0x40000400
#define STM32446Tim4addr 0x40000800
#define STM32446Tim5addr 0x40000C00
#define STM32446Tim9addr 0x40014000
#define STM32446Tim10addr 0x40014400
#define STM32446Tim11addr 0x40014800
#define STM32446IWdgaddr 0x40003000
#define STM32446WWdgaddr 0x40002C00
#define STM32446Rtcaddr 0x40002800
#define STM32446I2c1addr 0x40005400
#define STM32446I2c2addr 0x40005800
#define STM32446I2c3addr 0x40005C00
#define STM32446Usart1addr 0x40011000
#define STM32446Usart2addr 0x40004400
#define STM32446Usart6addr 0x40011400
#define STM32446Spi1i2s1addr 0x40013000
#define STM32446I2s2extaddr 0x40003400
#define STM32446Spi2i2s2addr 0x40003800
#define STM32446Spi3i2s3addr 0x40003C00
#define STM32446I2s3extaddr 0x40004000
#define STM32446Spi4i2s4addr 0x40013400
#define STM32446Spi5i2s5addr 0x40015000
#define STM32446SDioaddr 0x40012C00
#define Usb_Otg_Globaladdr 0
#define Usb_Otg_Deviceaddr 0
#define Usb_Otg_INEndpointaddr 0
#define Usb_Otg_OUTEndpointaddr 0
#define Usb_Otg_Hostaddr 0
#define Usb_Otg_HostChanneladdr 0
#define STM32446DbgMcuaddr 0xE0042000
/************/
#define STM32446TPiuaddr 0xE0040004
#define STM32446DeviceIdaddr 0x1FFF7A10
#define STM32446FlashSizeaddr 0x1FFF7A22
/*
***
*/
// Low Word High Word
typedef struct STM32446LowHigh{
	uint16_t L;
	uint16_t H;
}STM32446LowHigh;
/*
***
*/
STM32446 STM32446enable(void){ 
	STM32446 ret;
	ret.gpr = (STM32446Gpr*) STM32446Gpraddr;
	ret.pcr = (STM32446Pcr*) STM32446Pcraddr;
	ret.mpu = (STM32446Mpu*) STM32446Mpuaddr;
	/************/
	ret.flash = (STM32446Flash*) STM32446Flashaddr;
	ret.crc = (STM32446Crc*) STM32446Crcaddr;
	ret.pwr = (STM32446Pwr*) STM32446Pwraddr;
	ret.rcc = (STM32446Rcc*) STM32446Rccaddr;
	ret.syscfg = (STM32446SysCfg*) STM32446SysCfgaddr;
	ret.gpioa = (STM32446GpioA*) STM32446GpioAaddr;
	ret.gpiob = (STM32446GpioB*) STM32446GpioBaddr;
	ret.gpioc = (STM32446GpioC*) STM32446GpioCaddr;
	ret.gpiod = (STM32446GpioD*) STM32446GpioDaddr;
	ret.gpioe = (STM32446GpioE*) STM32446GpioEaddr;
	ret.gpioh = (STM32446GpioH*) STM32446GpioHaddr;
	ret.dma1 = (STM32446Dma1*) STM32446Dma1addr;
	ret.dma2 = (STM32446Dma2*) STM32446Dma2addr;
	ret.exti = (STM32446Exti*) STM32446Extiaddr;
	ret.adc1 = (STM32446Adc1*) STM32446Adc1addr;
	ret.tim1 = (STM32446Tim1*) STM32446Tim1addr;
	ret.tim2 = (STM32446Tim2*) STM32446Tim2addr;
	ret.tim3 = (STM32446Tim3*) STM32446Tim3addr;
	ret.tim4 = (STM32446Tim4*) STM32446Tim4addr;
	ret.tim5 = (STM32446Tim5*) STM32446Tim5addr;
	ret.tim9 = (STM32446Tim9*) STM32446Tim9addr;
	ret.tim10 = (STM32446Tim10*) STM32446Tim10addr;
	ret.tim11 = (STM32446Tim11*) STM32446Tim11addr;
	ret.iwdg = (STM32446IWdg*) STM32446IWdgaddr;
	ret.wwdg = (STM32446WWdg*) STM32446WWdgaddr;
	ret.rtc = (STM32446Rtc*) STM32446Rtcaddr;
	ret.i2c1 = (STM32446I2c1*) STM32446I2c1addr;
	ret.i2c2 = (STM32446I2c2*) STM32446I2c2addr;
	ret.i2c3 = (STM32446I2c3*) STM32446I2c3addr;
	ret.usart1 = (STM32446Usart1*) STM32446Usart1addr;
	ret.usart2 = (STM32446Usart2*) STM32446Usart2addr;
	ret.usart6 = (STM32446Usart6*) STM32446Usart6addr;
	ret.spi1i2s1 = (STM32446Spi1i2s1*) STM32446Spi1i2s1addr;
	ret.i2s2ext = (STM32446I2s2ext*) STM32446I2s2extaddr;
	ret.spi2i2s2 = (STM32446Spi2i2s2*) STM32446Spi2i2s2addr;
	ret.spi3i2s3 = (STM32446Spi3i2s3*) STM32446Spi3i2s3addr;
	ret.i2s3ext = (STM32446I2s3ext*) STM32446I2s3extaddr;
	ret.spi4i2s4 = (STM32446Spi4i2s4*) STM32446Spi4i2s4addr;
	ret.spi5i2s5 = (STM32446Spi5i2s5*) STM32446Spi5i2s5addr;
	ret.sdio = (STM32446SDio*) STM32446SDioaddr;
	ret.otg_global = (Usb_Otg_Global*) Usb_Otg_Globaladdr; 
	ret.otg_device = (Usb_Otg_Device*) Usb_Otg_Deviceaddr;
	ret.otg_inendpoint = (Usb_Otg_INEndpoint*) Usb_Otg_INEndpointaddr;
	ret.otg_outendpoint = (Usb_Otg_OUTEndpoint*) Usb_Otg_OUTEndpointaddr;
	ret.otg_host = (Usb_Otg_Host*) Usb_Otg_Hostaddr;
	ret.otg_hostchannel = (Usb_Otg_HostChannel*) Usb_Otg_HostChanneladdr;
	ret.dbgmcu = (STM32446DbgMcu*) STM32446DbgMcuaddr;
	/************/
	ret.tpiu = (STM32446TPiu*) STM32446TPiuaddr;
	ret.deviceid = (STM32446DeviceId*) STM32446DeviceIdaddr;
	ret.flashsize = (STM32446FlashSize*) STM32446FlashSizeaddr;
	return ret;
}
/***EOF***/
/*** COMMENT
***/
