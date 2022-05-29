/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/
#ifndef PORT_H_
#define PORT_H_

#include <stdint.h>
#include "Std_Types.h"

#include "Port_Cfg.h"

typedef enum
{
    PORT_PIN_IN = 0, 
    PORT_PIN_OUT
} Port_PinDirectionType;

typedef uint8_t  Port_PinType;
typedef uint32_t Port_PinModeType;

typedef struct _Port_ConfigType
{
    Port_PinType          pinType;
    Port_PinModeType      pinModeType;
    Port_PinDirectionType pinDirectionType;
} Port_ConfigType;

void Port_Init(const Port_ConfigType *configType);

#endif