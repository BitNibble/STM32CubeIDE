/************************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
	Tested Atemga128 16Mhz and Atmega328 8Mhz and STM32F446RE
************************************************************************/
#ifndef _EXPLODE_H_
	#define _EXPLODE_H_
/***Library***/
#include <inttypes.h>
/***Constant & Macro***/
/***Global Variable***/
typedef struct expld{
	/***Variable***/
	uint32_t XI;
	uint32_t XF;
	uint32_t HH;
	uint32_t LL;
	uint32_t LH;
	uint32_t HL;
	/***PROTOTYPES VTABLE***/
	void (*update)(struct expld* self, uint32_t x);
}EXPLODE;
/***Header***/
EXPLODE EXPLODEenable(void);
#endif
/***comment***
**************/
/***EOF***/

