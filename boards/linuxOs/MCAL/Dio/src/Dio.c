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


#include "Std_Types.h"
#include "Dio.h"
#include <string.h>

#if 0
Dio_PortLevelType Dio_ReadPort(Dio_PortType portId)
{
	Dio_LevelType level = 0;

	// level = GPIO_ReadInputData(GPIO_ports[portId]);

	return level;
}

void Dio_WritePort(Dio_PortType portId, Dio_PortLevelType level)
{

	//GPIO_Write(GPIO_ports[portId], level);

	return;
}
#endif
Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelId)
{
	Dio_LevelType level;

	Dio_PortLevelType portVal = Dio_ReadPort(DIO_GET_PORT_FROM_CHANNEL_ID(channelId));
	Dio_PortLevelType bit = DIO_GET_BIT_FROM_CHANNEL_ID(channelId);

	if ((portVal & bit) != STD_LOW)
	{
		level = STD_HIGH;
	} 
	else
	{
		level = STD_LOW;
	}

	return (level);
}

void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level)
{
	return;
}

