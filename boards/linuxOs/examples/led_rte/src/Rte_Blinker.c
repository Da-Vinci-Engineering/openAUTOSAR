/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/


/* Rte_Blinker.c */
#include <string.h>
#include "Os.h"
#include "Rte_Blinker.h"
#include "Rte_Data.h"
#include "Rte_EcuAbstraction.h"

Std_ReturnType Rte_Call_Blinker_LED_Port_Set(const DigitalLevel value) 
{
	return Rte_DigitalOutput_Set(0, value);
}

