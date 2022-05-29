/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/

#include <string.h>
#include "MemMap.h"
#include "Port.h"

typedef enum
{
    PORT_UNINITIALIZED = 0, 
    PORT_INITIALIZED
} Port_StateType;

static Port_StateType _portState = PORT_UNINITIALIZED;
static Port_ConfigType * _configPtr = NULL;

void Port_Init(const Port_ConfigType *configType)
{
    _portState = PORT_INITIALIZED;
    _configPtr = (Port_ConfigType *)configType;
    return;
}


#if 0
void Port_SetPinDirection( Port_PinType pin, Port_PinDirectionType direction )
{
  return;
}
#endif

#if 0
void Port_RefreshPortDirection(void)
{
    return;
}

void Port_GetVersionInfo(Std_VersionInfoType* versionInfo)
{
    return;
}
#endif

#if 0
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    return;
}
#endif
