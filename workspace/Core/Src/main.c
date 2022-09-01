/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

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


static STM32446 stm;
static FUNC func;
static EXPLODE PINA;
static EXPLODE PINB;
static EXPLODE PINC;
static HC595 hc;
static LCD0 lcd;

static uint8_t choice;
static uint8_t hour = 0;
static uint8_t minute = 0;
static uint8_t second = 0;
static uint8_t ano = 0;
static uint8_t mes = 1;
static uint8_t dia = 1;
static uint32_t value = 0;

static int8_t count1;
static uint16_t count2;
static uint8_t dir;
static char vec[24];

void portinic(void);
void tim9inic(void);
void adc1inic(void);
void calendario(void);

void TIM1_BRK_TIM9_IRQHandler(void);

int main(void)
{
double temperature = 0;
unsigned int samples = 0;
const int n_samples = 60;
stm = STM32446enable(); // stm object
stm.inic.peripheral();
portinic();
tim9inic();
func = FUNCenable();
PINA = EXPLODEenable();
PINB = EXPLODEenable();
PINC = EXPLODEenable();
choice = 3;
count1 = 0;
count2 = 0;
dir = 0;
// Initialize objects after portinic()
hc = HC595enable(&stm.gpioc.reg->MODER, &stm.gpioc.reg->ODR, 2, 1, 0);
lcd = LCD0enable(stm.gpiob.reg);


stm.adc1.Ex1inic();
stm.rtc.inic(1); // 0 - LSI, 1 - LSE

stm.systick.delay_ms(10);

stm.rtc.RegWrite( &stm.rtc.reg->BKP0R, (('\0' << 24) | ('B' << 16) | ('U' << 8) | ('C' << 0)) );

while (1)
{
	// Preamble
	PINA.update(&PINA, stm.gpioa.reg->IDR);
	PINB.update(&PINB, stm.gpiob.reg->IDR);
	PINC.update(&PINC, stm.gpioc.reg->IDR);
	lcd.reboot();
	/***************/
	calendario();

	lcd.gotoxy(1,0);
	lcd.string( func.print("%s", &stm.rtc.reg->BKP0R ));


	lcd.gotoxy(1,4);
	if(samples < n_samples){
		temperature += stm.adc1.read();
		stm.adc1.restart();
		samples++;
	}else{
		temperature /= n_samples;
		temperature = (temperature/3.1 - 943/3.1) + 25;
		lcd.string_size( func.print("%d %cC", (unsigned int)temperature, (char) 0xDF ), 7);
		samples=0;
	  }
}
}

void portinic(void)
{
	//Enable clock for IO peripherals
	stm.rcc.reg->AHB1ENR |= 7; //PA PB PC clock enabled
  	// GPIO of 16 pins each.
	/**************************/
  	// PA5 or PB13 is green user led
	stm.func.setupreg(2, &stm.gpioa.reg->MODER, 1, 5);
	stm.func.setupreg(2, &stm.gpioa.reg->PUPDR, 0, 5);
	//stm.func.setupreg(1, &stm.gpiob.reg->MODER, 1, 26);

	// PC13 is user button
	stm.func.setupreg(2, &stm.gpioc.reg->MODER, 0, 13);
	stm.func.setupreg(2, &stm.gpioc.reg->PUPDR, 1, 13);

	// PC1 PC2 PC3 as output
	stm.func.setupreg(2, &stm.gpioc.reg->MODER, 1, 0);
	stm.func.setupreg(2, &stm.gpioc.reg->MODER, 1, 1);
	stm.func.setupreg(2, &stm.gpioc.reg->MODER, 1, 2);
	stm.func.setupreg(2, &stm.gpioc.reg->PUPDR, 0, 0);
	stm.func.setupreg(2, &stm.gpioc.reg->PUPDR, 0, 1);
	stm.func.setupreg(2, &stm.gpioc.reg->PUPDR, 0, 2);
}

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

void calendario(void)
{
	/******MENU*****/
	switch(choice){
		case 1: // show time
			lcd.gotoxy(0,0);
			lcd.string_size("Relogio",16);
			stm.rtc.tr2vec(vec);
			lcd.gotoxy(3,0);
			lcd.string_size(func.print("hora: %d%d:%d%d:%d%d", vec[0],vec[1],vec[2],vec[3],vec[4],vec[5]),17);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 5 && value < 11 )
				choice = 2;
			if( value > 10 && value < 30 )
				choice = 4;
			if( value > 40 )
				choice = 3;
			break;

		case 2: // show date
			lcd.gotoxy(0,0);
			lcd.string_size("Data",16);
			stm.rtc.dr2vec(vec);
			lcd.gotoxy(3,0);
			lcd.string_size(func.print("data: %d%d:%d%d:20%d%d", vec[5],vec[6],vec[3],vec[4],vec[0],vec[1]),17);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 5 && value < 11 )
				choice = 1;
			if( value > 10 && value < 30 )
				choice = 7;
			if( value > 40 )
				choice = 3;
			break;

		case 3: // message
			lcd.gotoxy(0,0);
			lcd.string_size("Calendario",16);

			stm.rtc.dr2vec(vec);
			lcd.gotoxy(2,0);
			lcd.string_size(func.print("data: %d%d:%d%d:20%d%d", vec[5],vec[6],vec[3],vec[4],vec[0],vec[1]),17);

			stm.rtc.tr2vec(vec);
			lcd.gotoxy(3,0);
			lcd.string_size(func.print("hora: %d%d:%d%d:%d%d", vec[0],vec[1],vec[2],vec[3],vec[4],vec[5]),17);

			if(stm.func.triggerB(PINC.HL,PINC.LH,13,count2) > 40){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",17);
				lcd.gotoxy(3,0);
				lcd.string_size(" ",15);
				choice = 1;
			}
			break;

		// Relogio
		case 4: // Set Hour
			lcd.gotoxy(0,0);
			lcd.string_size("Acertar Hora",16);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 0 && value < 6){
				hour ++;
				if(hour > 23)
					hour = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func.print("hora: %d", hour),16);
			}
			if( value > 10 && value < 20){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 5;
			}
			if( value > 19){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 1;
				stm.rtc.Hour(hour);
			}
			break;

		case 5: // Set Minute
			lcd.gotoxy(0,0);
			lcd.string_size("Acertar Minutos",16);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 0 && value < 6){
				minute ++;
				if(minute > 59)
					minute = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func.print("minuto: %d", minute),16);
			}
			if( value > 10 && value < 20){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 6;
			}
			if( value > 19){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 1;
				stm.rtc.Minute(minute);
			}
			break;

		case 6: // Set Second
			lcd.gotoxy(0,0);
			lcd.string_size("Acertar Segundos",16);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 0 && value < 6){
				second ++;
				if(second > 59)
					second = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func.print("segundo: %d", second),16);
			}
			if( value > 10 && value < 20){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 1;
			}
			if( value > 19){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 1;
				stm.rtc.Second(second);
			}
			break;

			// Calendario
			case 7: // Set Year
			lcd.gotoxy(0,0);
			lcd.string_size("Acertar Ano",16);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 0 && value < 6){
				ano ++;
				if(ano > 99)
					ano = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func.print("Ano: %d", ano),16);
			}
			if( value > 10 && value < 20){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 8;
			}
			if( value > 19){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 2;
				stm.rtc.Year(ano);
			}
			break;

		case 8: // Set Month
			lcd.gotoxy(0,0);
			lcd.string_size("Acertar Mes",16);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 0 && value < 6){
				mes ++;
				if(mes > 12)
					mes = 1;
				lcd.gotoxy(2,0);
				lcd.string_size(func.print("mes: %d", mes),16);
			}
			if( value > 10 && value < 20){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 9;
			}
			if( value > 19){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 2;
				stm.rtc.Month(mes);
			}
			break;

		case 9: // Set Day
			lcd.gotoxy(0,0);
			lcd.string_size("Acertar Dia",16);
			value = stm.func.triggerB(PINC.HL,PINC.LH,13,count2);
			if( value > 0 && value < 6){
				dia ++;
				if(dia > 31)
					dia = 1;
				lcd.gotoxy(2,0);
				lcd.string_size(func.print("dia: %d", dia),16);
			}
			if( value > 10 && value < 20){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 2;
			}
			if( value > 19){
				lcd.gotoxy(2,0);
				lcd.string_size(" ",16);
				choice = 2;
				stm.rtc.Day(dia);
			}
			break;
		default:
			break;
	}
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
  while (1)
  {

  }
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif /* USE_FULL_ASSERT */
/******************************************************************************/
