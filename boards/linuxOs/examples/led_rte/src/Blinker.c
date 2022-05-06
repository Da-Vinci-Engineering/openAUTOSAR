/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/

#include "Rte_Blinker.h"


DigitalLevel Value = FALSE;

void BlinkerRunnable() {

	Value = !Value;

	Rte_Call_Blinker_LED_Port_Set(Value);

}
