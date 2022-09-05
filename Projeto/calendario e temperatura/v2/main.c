/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Calendario e temperatura
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
  * Nucleo -F446RE board from STM32nucleo
  *
  * PC 0,1,2 ---> 74HC595
  * PB 0...7 ---> LCD 4x20
  * PA 5     ---> Led indicator
  * PC 13    ---> user button
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

#define sperm ~0
#define ass (1)

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
static volatile uint32_t vect[8];

void portinic(void);
void tim9inic(void);
void calendario(void);

void TIM1_BRK_TIM9_IRQHandler(void);

int main(void)
{
unsigned int workspace;
unsigned int zone;
double temperature = 0;
unsigned int samples = 0;
const int n_samples = 60;
vect[0] = 0;
vect[1] = 0;
vect[2] = 0;

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

stm.adc1.single.inic();
stm.adc1.single.temp();
stm.adc1.single.start();

stm.rtc.inic(1); // 2 - LSI, 1 - LSE
//stm.systick.delay_ms(10);

/******************************************************************************/
/***************************** TEST STUFF START *******************************/
/******************************************************************************/

//1 - Enable access to the RTC registers
stm.pwr.reg->CR |= (1 << 8); // Disable backup domain write protection
//2 - Enter the "key" to unlock write protection
stm.rtc.reg->WPR |= 0xCA;
stm.rtc.reg->WPR |= 0x53;
//3 - Write
stm.func.setup(&stm.rtc.reg->BKP0R, 8, 'S', 0);
stm.func.setup(&stm.rtc.reg->BKP0R, 8, 'E', 1);
stm.func.setup(&stm.rtc.reg->BKP0R, 8, 'T', 2);
stm.func.setup(&stm.rtc.reg->BKP0R, 8, 'H', 3);
stm.func.setup(&stm.rtc.reg->BKP0R, 8, 'S', 4);
stm.func.setup(&stm.rtc.reg->BKP0R, 8, '\0', 5);
//stm.rtc.RegWrite( &stm.rtc.reg->BKP0R, ( ('\0' << 24) | ('T' << 16) | ('E' << 8) | ('S' << 0)) );
//4 - Disable access to RTC registers
stm.pwr.reg->CR &= (uint32_t) ~(1 << 8);


//stm.func.setup(vect, 16, 1, 0);
//stm.func.setup(vect, 16, 1, 2);
//lcd.gotoxy(0,14);
//lcd.string_size( func.print("%d", vect[0]), 9);

//lcd.gotoxy(1,14);
//lcd.string_size( func.print("%d", vect[1]), 9);

stm.rcc.reg->APB2ENR |= (1 << 4); // USART1EN: USART1 clock enable
stm.gpioa.moder(2,9);
stm.gpioa.moder(2,10);
stm.gpioa.afr(7,9);
stm.gpioa.afr(7,10);
stm.usart1.reg->CR1 |= (1 << 13); // UE: USART enable
stm.usart1.parameters( 8, 16, 1, 9600 ); // Default
stm.usart1.reg->CR3 &= (uint32_t) ~(1 << 7); // DMAT: DMA enable transmitter - disabled
stm.usart1.reg->CR1 |= (1 << 3); // TE: Transmitter enable
stm.usart1.reg->DR = 'A';
//on real application, use fall threw method in main
//for( ; stm.usart1.reg->SR & (1 << 6); ); // TC: Transmission complete
// added this as disable after confirmed end of transmission [9]
//ret.usart1.reg->CR1 &= (uint32_t) ~(1 << 13); // UE: USART disable



/******************************************************************************/
/*****************************  TEST STUFF END  *******************************/
/******************************************************************************/
				/************************************/
/******************************************************************************/
for ( zone = 0, workspace = 0 ; ass ; workspace++)
{// COMMON
zone = workspace & 7;

if(zone == 0)
{// PREAMBLE
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
	lcd.gotoxy(1,0);
	lcd.string( func.print("%s", &stm.rtc.reg->BKP0R ));

	lcd.gotoxy(1,7);
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
if(zone == 2)
{// workspace 2

	lcd.gotoxy(1,0);
	lcd.string( func.print("%s", &stm.rtc.reg->BKP0R ));


	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 3)
{// workspace 3

	calendario();

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 4)
{// workspace 4
	//stm.usart1.parameters(8,16,1,9600);
	//stm.usart1.test();


	if( stm.usart1.reg->SR & (1 << 6) ){ // TC: Transmission complete
		//stm.usart1.reg->DR = 'B';
		//lcd.gotoxy(0,17);
		//lcd.string_size( func.print("%d",zone), 3);
	}

	continue;
} // if
/******************************************************************************/


/******************************************************************************/
} // for
} // main
/******************************************************************************/
		/*************************************************************/
/******************************************************************************/
/******************************************************************************/
		/*************************************************************/
/******************************************************************************/
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
			lcd.string_size("Calendario",10);

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
/******************************************************************************/
/******************************************************************************
#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif
******************************************************************************/

