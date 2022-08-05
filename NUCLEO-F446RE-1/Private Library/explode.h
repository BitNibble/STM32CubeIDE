/************************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:

************************************************************************/
#ifndef _EXPLODE_H_
	#define _EXPLODE_H_
/***Library***/
#include <inttypes.h>
/***Constant & Macro***/
/***Global Variable***/
struct expld{
	/***Variable***/
	uint32_t XI;
	uint32_t XF;
	uint32_t HH;
	uint32_t LL;
	uint32_t LH;
	uint32_t HL;
	/***PROTOTYPES VTABLE***/
	void (*update)(struct expld* self, uint32_t x);
	struct expld (*read)(struct expld* self);
};
typedef struct expld EXPLODE;
/***Header***/
EXPLODE EXPLODEenable(void);
#endif
/***comment***
**************/
/***EOF***/
