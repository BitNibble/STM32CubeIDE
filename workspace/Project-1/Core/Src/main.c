/******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
*******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  * Nucleo -F446RE board from STM32nucleo
  *
  * PC 0,1,2 		---> 74HC595
  * PB 0...7 		---> LCD 4x20
  * PA 5     		---> Led indicator
  * PC 13    		---> user button
  * PA9 and PA10 	---> USART1
  *
*******************************************************************************/
/******************************************************************************/
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "stm32446mapping.h"
#include "function.h"
#include "explode.h"
#include "74hc595.h"
#include "lcd.h"
#include "circbuffer.h"

static STM32446 stm;
static FUNC func;
static EXPLODE PINA;
static EXPLODE PINB;
static EXPLODE PINC;
static HC595 hc;
static LCD0 lcd;
static circbuff circ;
static circbuff circ2;

static int8_t count1;
static uint16_t count2;
static uint8_t dir;

void portinic(void);
void tim9inic(void);
void calendario(void);

void TIM1_BRK_TIM9_IRQHandler(void);
/******************************************************************************/
int main(void)
{
unsigned int workspace;
unsigned int zone;
uint8_t transmit;
uint8_t receive;
uint32_t value;

double temperature = 0;
unsigned int samples = 0;
const int n_samples = 60;

uint8_t buffer[32]; // for circular buffer
uint8_t buffer2[32]; // for circular buffer
uint8_t received[32]; // for circular buffer

stm = STM32446enable(); // stm object
stm.inic.peripheral();
portinic();
tim9inic();

func = FUNCenable();
PINA = EXPLODEenable();
PINB = EXPLODEenable();
PINC = EXPLODEenable();
circ = CIRCBUFFenable(32, buffer);
circ2 = CIRCBUFFenable(32, buffer2);

count1 = 0;
count2 = 0;
dir = 0;

// Initialize objects after portinic()
hc = HC595enable(&stm.gpioc.reg->MODER, &stm.gpioc.reg->ODR, 2, 1, 0);
lcd = LCD0enable(stm.gpiob.reg);

stm.adc1.single.inic();
stm.adc1.single.temp();
stm.adc1.single.start();

stm.usart1.inic(8, 16, 1, 9600);
stm.usart1.transmit();
stm.usart1.receive();

/***************************** TEST STUFF START *******************************/


/*****************************  TEST STUFF END  *******************************/

for ( zone = 0, workspace = 0 ; (1) ; workspace++)
{// COMMON
zone = workspace & 7;

if(zone == 0)
{// PREAMBLE PREAMBLE COMMON

	PINA.update(&PINA, stm.gpioa.reg->IDR);
	PINB.update(&PINB, stm.gpiob.reg->IDR);
	PINC.update(&PINC, stm.gpioc.reg->IDR);
	lcd.reboot();
	// Detect for all workspaces only once

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 1)
{// workspace 1
	value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
	if( value > 5 && value < 11 ){
		circ.putstr(&circ, "5 to 10 pulse press\r\n" );
	}
	if( value > 10 && value < 30 ){
		circ.putstr(&circ, "10 to 30 pulse press\r\n");
	}
	if( value > 40 ){
		circ.putstr(&circ, "More than 40 pulse press\r\n");
	}

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 2)
{// workspace 2 ADC1 TEMPERATURE

	lcd.gotoxy(1,0);
	if(samples < n_samples){
		temperature += stm.adc1.single.read();
		stm.adc1.single.restart();
		samples++;
	}else{
		temperature /= n_samples;
		temperature = (temperature/3.1 - 943/3.1) + 25;
		lcd.string_size( func.print("%d %cC", (unsigned int)temperature, (char) 0xDF ), 6);
		samples=0;
	}

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 3)
{// workspace 3 USART1 TX RX

	if( stm.usart1.reg->SR & (1 << 6) ){ // TC: Transmission complete

		transmit = circ.get(&circ);
		if(transmit)
			stm.usart1.reg->DR = transmit;

	}

	if(stm.usart1.reg->SR & (1 << 5)){ // RXNE: Read data register not empty
		receive = stm.usart1.reg->DR;
		if(receive){
			circ2.put(&circ2, receive);

			if(receive == 13 ){
				circ2.getstr(&circ2, received);
				lcd.gotoxy(1,6);
				received[strlen((char*)received)-1] = '\0'; //remove enter key [13]
				lcd.string_size((char*)received, 14);
			}

		}
		stm.usart1.reg->SR &=  ~(1 << 5);
	}

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 4)
{// workspace 4
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 5)
{// workspace 5
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 6)
{// workspace 6
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 7)
{// workspace 7
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
} // for
} // main

/******************************************************************************/
		/*************************************************************/
/******************************************************************************/

void portinic(void)
{
	//Enable clock for IO peripherals
	stm.rcc.reg->AHB1ENR |= 7; //PA PB PC clock enabled
  	// GPIO of 16 pins each.
	/**************************/
  	// PA5 or PB13 is green user led
	stm.gpioa.moder(1,5);
	stm.gpioa.pupdr(0,5);
	//stm.gpiob.moder(1,13);

	// PC13 is user button
	stm.gpioc.moder(0,13);
	stm.gpioc.pupdr(1,13);
}

/******************************************************************************/

void tim9inic(void)
{
	stm.rcc.reg->APB2ENR |= (1 << 16); //timer 9 clock enabled
	//stm.rcc.reg->APB2ENR |= (1 << 14); //syscfg clock enable
	stm.nvic.reg->ISER[0] |= (1 << 24); // enable interrupt tim 1 brk and tim 9 global (IRGn 24)
	//stm.nvic.reg->ICER[0] |= (1 << 24);
	stm.tim9.reg->ARR = 45535;
	stm.tim9.reg->CCR1 = 7530;
	stm.tim9.reg->PSC = 20;
	stm.tim9.reg->DIER |= 3; //3 | (1 << 6);
	//stm.tim9.reg->CCMR1 |= (3 << 2);
	//stm.tim9.reg->CCMR1 |= (3 << 4);
	//stm.tim9.reg->CCER |= 1;
	stm.tim9.reg->CR1 |= 1 | (1 << 7);
}

/******************************************************************************/
/******************************************************************************/

/***Interrupt Definition***/

void TIM1_BRK_TIM9_IRQHandler(void)
{
	/***/
	if(stm.tim9.reg->SR & 1){ // status register (view interrupt flags)
		stm.tim9.reg->SR &=  (uint32_t) ~1;

		if(dir){
			stm.gpioa.reset(1 << 5);

			hc.byte((uint8_t)~(1 << count1--));
			if(count1 < 0)
				dir = 0;
		}else{
			stm.gpioa.set(1 << 5);

			hc.byte((uint8_t)~(1 << count1++));
			if(count1 > 7)
				dir = 1;
		}
		count2++;
	}
	if(stm.tim9.reg->SR & 2){
		stm.tim9.reg->SR &=  (uint32_t) ~2;

	}
	/***/
	//stm.tim9.reg->SR &=  (uint32_t) ~1;
	//stm.tim9.reg->SR &=  (uint32_t) ~2;
}

/******************************************************************************/
void Error_Handler(void)
{
  __disable_irq();

  perror("error\n");
  //while (1)
  //{

  //}
}
/******************************************************************************/
/******************************************************************************
#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif
*******************************************************************************/
/******************************** COMMENT *************************************

*******************************************************************************/
/***EOF***/

