/********************************************************************
	TEST
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com> 
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
    Pin Analysis
    Tested Atemga128 16Mhz and Atmega328 8Mhz and STM32F446RE
********************************************************************/
#include "test.h"

TEST TESTenable(void)
{
	TEST test;
	test.testa = 999;
	return test;
}

