/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/

#ifndef RTE_DATA_H
#define RTE_DATA_H

#include "Rte_Type.h"
#include "cirq_buffer.h"

void Rte_BlinkerRunnable(void);

Std_ReturnType Rte_DigitalOutput_Set(IoHwAb_SignalType SignalId,
		const DigitalLevel value);

#endif
