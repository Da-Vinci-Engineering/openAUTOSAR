/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 *******************************************************************/
#ifndef NVM_EXT_H_
#define NVM_EXT_H_

#include "Std_Types.h"
#include "MemIf_Types.h"

Std_ReturnType MemIf_Read(uint8 DeviceIndex, uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length);
Std_ReturnType MemIf_Write(uint8 DeviceIndex, uint16 BlockNumber, uint8 *DataBufferPtr);
MemIf_StatusType MemIf_GetStatus(uint8 DeviceIndex);
MemIf_JobResultType MemIf_GetJobResult(uint8 DeviceIndex);
Std_ReturnType MemIf_InvalidateBlock(uint8 DeviceIndex, uint16 BlockNumber);

#endif // NVM_EXT_H_