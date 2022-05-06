/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

#include "Rte_Type.h"
#include "IoHwAb.h"

#if defined(IOHWAB_SIGNAL_COUNT_ANALOG_VOLT)
Std_ReturnType VoltageInput_Get(IoHwAb_SignalType signalId,
		MilliVolt* value, SignalQuality* quality)
{
	Std_ReturnType rv;
	IoHwAb_StatusType s;

	rv = IoHwAb_Get_Volt( signalId, value, &s );
	*quality = (SignalQuality)s.quality;
   return rv;
}
#endif

#if defined(IOHWAB_SIGNAL_COUNT_ANALOG_AMPERE)
Std_ReturnType CurrentInput_Get(IoHwAb_SignalType signalId,
		MilliAmpere* value, SignalQuality* quality)
{
	Std_ReturnType rv;
	IoHwAb_StatusType s;

	rv = IoHwAb_Get_Ampere( signalId, value, &s );
	*quality = (SignalQuality)s.quality;
   return rv;
}
#endif

#if defined(IOHWAB_SIGNAL_COUNT_ANALOG_OHM)
Std_ReturnType ResistanceInput_Get(IoHwAb_SignalType signalId,
		MilliOhm* value, SignalQuality* quality)
{
	Std_ReturnType rv;
	IoHwAb_StatusType s;

	rv = IoHwAb_Get_Ohm( signalId, value, &s );
	*quality = (SignalQuality)s.quality;
   return rv;
}
#endif

Std_ReturnType DigitalInput_Get(IoHwAb_SignalType signalId,
		DigitalLevel* value, SignalQuality* quality)
{
	Std_ReturnType rv;
	IoHwAb_StatusType s;

	rv = IoHwAb_Get_Digital( signalId, value, &s );
	*quality= (SignalQuality)s.quality;
    return rv;
}


Std_ReturnType DigitalOutput_Set(IoHwAb_SignalType signalId,
		const DigitalLevel value)
{
	IoHwAb_StatusType status;
	return IoHwAb_Set_Digital( signalId, value, &status );
}

Std_ReturnType DigitalOutput_ReadBack(IoHwAb_SignalType signalId,
		DigitalLevel* value)
{
	Std_ReturnType rv;
	IoHwAb_StatusType s;

	rv = IoHwAb_Get_Digital( signalId, value, &s );
   return rv;
}

Std_ReturnType PWMDutyOutput_Set(IoHwAb_SignalType signalId,
		const Percent value)
{
	IoHwAb_StatusType status;
	return IoHwAb_Set_Duty( signalId, value, &status );
}

Std_ReturnType PWMDutyAndFrequencyOutput_Set(IoHwAb_SignalType signalId,
		const Percent duty, const Hertz freq)
{
	IoHwAb_StatusType status;
   /* Reversing makes it so much more fun */
	return IoHwAb_Set_FrequencyAndDuty( signalId, freq, duty, &status );
}
