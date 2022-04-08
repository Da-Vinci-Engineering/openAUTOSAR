/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 *******************************************************************/
#ifndef MEMIF_EXT_H_
#define MEMIF_EXT_H_

#include "Std_Types.h"
#include "MemIf_Types.h"

void Fee_MainFunction(void);
void Fee_Init(void);
void Fee_SetMode(MemIf_ModeType mode);
Std_ReturnType Fee_Read(uint16 blockNumber, uint16 blockOffset, uint8* dataBufferPtr, uint16 length);
Std_ReturnType Fee_Write(uint16 blockNumber, uint8* dataBufferPtr);
void Fee_Cancel(void);
MemIf_StatusType Fee_GetStatus(void);
MemIf_JobResultType Fee_GetJobResult(void);
Std_ReturnType Fee_InvalidateBlock(uint16 blockNumber);
Std_ReturnType Fee_EraseImmediateBlock(uint16 blockNumber);


#endif // MEMIF_EXT_H_