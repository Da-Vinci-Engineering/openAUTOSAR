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


#warning "This default file may only be used as an example!"

#ifndef CANTP_CFG_H_
#define CANTP_CFG_H_

#include "CanTp_Types.h"

#define CANTP_MAIN_FUNCTION_PERIOD_TIME_MS	1000
#define CANTP_CONVERT_MS_TO_MAIN_CYCLES(x) 	(x)/CANTP_MAIN_FUNCTION_PERIOD_TIME_MS

#define CANTP_NSDU_CONFIG_LIST_SIZE		4
#define CANTP_NSDU_RUNTIME_LIST_SIZE	4

#define FRTP_CANCEL_TRANSMIT_REQUEST 	STD_ON
#define CANTP_VERSION_INFO_API          STD_ON   /**< Build version info API */
#define CANTP_DEV_ERROR_DETECT          STD_ON

/********************************************************************
 * TODO
 * The constants below are not defined in the code base from Arctic
 * Their values have to be checked in real Projects
 * (C) DaVinci Engineering GmbH 2022
 *******************************************************************/
#define CANTP_RXID_LIST_SIZE 10

extern CanTp_ConfigType CanTpConfig;
extern const CanTp_NSduType CanTpNSduConfigList[];


/*
 * Interfaces for callback notifications from PduR and ComM (8.4)
 */
extern BufReq_ReturnType Dcm_ProvideRxBuffer(PduIdType dcmRxPduId, PduLengthType tpSduLength, PduInfoType **pduInfoPtr);
extern void Dcm_RxIndication(PduIdType dcmRxPduId, NotifResultType result);
extern BufReq_ReturnType Dcm_ProvideTxBuffer(PduIdType dcmTxPduId, PduInfoType **pduInfoPtr, PduLengthType length);
extern void Dcm_TxConfirmation(PduIdType dcmTxPduId, NotifResultType result);
extern void Dcm_ComM_NoComModeEntered(void);
extern void Dcm_ComM_SilentComModeEntered(void);
extern void Dcm_ComM_FullComModeEntered(void);

#endif /* CANTP_CFG_H_ */
