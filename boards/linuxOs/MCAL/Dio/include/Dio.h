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

#ifndef DIO_H_
#define DIO_H_

#include "Modules.h"
#include "Std_Types.h"

// API Service ID's
#define DIO_READCHANNEL_ID			0x00
#define DIO_WRITECHANNEL_ID			0x01

#define DIO_E_PARAM_INVALID_CHANNEL_ID 		10
#define DIO_E_PARAM_INVALID_PORT_ID 		20
#define DIO_E_PARAM_INVALID_GROUP_ID 		31

typedef uint32 Dio_ChannelType;
typedef uint32 Dio_PortType;
typedef uint8_t Dio_LevelType;
typedef uint8 Dio_PortLevelType;



#if 0
#define DIO_MODULE_ID			MODULE_ID_DIO
#define DIO_VENDOR_ID			VENDOR_ID_ARCCORE

#define DIO_SW_MAJOR_VERSION	1
#define DIO_SW_MINOR_VERSION	0
#define DIO_SW_PATCH_VERSION	0

#define DIO_AR_MAJOR_VERSION	3
#define DIO_AR_MINOR_VERSION	1
#define DIO_AR_PATCH_VERSION	5

#include "Dio_Cfg.h"


#if ( DIO_VERSION_INFO_API == STD_ON)
/** @req DIO139 */
#define Dio_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi,DIO)
#endif

#endif

Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelId);

void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level);

#endif /*DIO_H_*/
