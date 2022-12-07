/********************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com> 
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
	Pin Analysis
	Tested Atemga128 16Mhz and Atmega328 8Mhz and STM32F446RE
********************************************************************/
/*** File Library ***/
#include <stdlib.h>
#include"explode.h"

/*** File Constant & Macro ***/
#ifndef ZERO
	#define ZERO 0
#endif
#ifndef ONE
	#define ONE 1
#endif

/*** File Variable ***/

/*** File Header ***/
void EXPLODEupdate(EXPLODE* self, uint32_t x);
uint32_t EXPLODEhh(EXPLODE* self);
uint32_t EXPLODEll(EXPLODE* self);
uint32_t EXPLODElh(EXPLODE* self);
uint32_t EXPLODEhl(EXPLODE* self);

/*** Procedure & Function ***/
EXPLODE EXPLODEenable( void )
{
	// struct object
	struct expld explode;
	//explode=(struct expld*)calloc(1,sizeof(struct expld));
	//if(explode == NULL){
		//perror("explode at calloc");
	//}
	// inic VAR
	explode.XI=ZERO;
	explode.XF=ZERO;
	// function pointers
	explode.update = EXPLODEupdate;
	
	return explode;
}

// boot
void EXPLODEupdate(EXPLODE* self, uint32_t x)
{
	self->XI = self->XF;
	self->XF = x;
	self->HH = EXPLODEhh(self);
	self->LL = EXPLODEll(self);
	self->LH = EXPLODElh(self);
	self->HL = EXPLODEhl(self);
}

// hh
uint32_t EXPLODEhh(EXPLODE* self)
{
	uint32_t i;
	i = self->XI & self->XF;
	return i;
}

// ll
uint32_t EXPLODEll(EXPLODE* self)
{
	uint32_t i;
	i = self->XI | self->XF;
	return ~i;
}

// lh
uint32_t EXPLODElh(EXPLODE* self)
{
	uint32_t i;
	i = self->XI ^ self->XF;
	i &= self->XF;
	return i;
}

// hl
uint32_t EXPLODEhl(EXPLODE* self)
{
	uint32_t i;
	i = self->XF ^ self->XI;
	i &= self->XI;
	return i;
}

/*** File Interrupt***/
/***EOF***/

