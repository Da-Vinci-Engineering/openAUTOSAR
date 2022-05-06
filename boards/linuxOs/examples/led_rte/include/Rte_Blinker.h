/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/

#ifndef RTE_BLINKER_H
#define RTE_BLINKER_H

#include "Rte_Type.h"

#define RTE_E_DigitalOutput_E_NOT_OK 1

#define Rte_Call_LED_Port_Set Rte_Call_Blinker_LED_Port_Set

Std_ReturnType Rte_Call_Blinker_LED_Port_Set(const DigitalLevel value);

void BlinkerRunnable(void);

#endif
