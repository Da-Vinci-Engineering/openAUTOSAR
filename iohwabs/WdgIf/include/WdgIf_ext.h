/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 *******************************************************************/
#ifndef WDGIF_EXT_H_
#define WDGIF_EXT_H_


#include "Wdg.h"

extern void Wdg_Init (const Wdg_ConfigType* ConfigPtr);
extern void Wdg_Trigger (void);
extern Std_ReturnType Wdg_SetMode (WdgIf_ModeType Mode);

#endif // WDGIF_EXT_H_


