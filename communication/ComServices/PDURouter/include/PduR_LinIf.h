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








#ifndef PDUR_LINIF_H_
#define PDUR_LINIF_H_

#include "PduR.h"

#if PDUR_ZERO_COST_OPERATION == STD_OFF

void PduR_LinIfRxIndication(PduIdType LinRxPduId,const PduInfoType* PduInfoPtr);
void PduR_LinIfTxConfirmation(PduIdType LinTxPduId);
Std_ReturnType PduR_LinIfTriggerTransmit(PduIdType LinTxPduId,PduInfoType* PduInfoPtr);

#endif

#endif /*PDUR_LINIF_H_*/



