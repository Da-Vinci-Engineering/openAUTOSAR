/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/
#ifndef PORT_H_
#define PORT_H_

#define PORT_SW_MAJOR_VERSION 1
#define PORT_SW_MINOR_VERSION 0
#define PORT_SW_PATCH_VERSION 0

#define PORT_AR_MAJOR_VERSION 3
#define PORT_AR_MINOR_VERSION 1
#define PORT_AR_PATCH_VERSION 0

#include <stdint.h>
#include "Std_Types.h"

#include "Port_Cfg.h"

#define PORT_E_PARAM_PIN              0x0a
#define PORT_E_DIRECTION_UNCHANGEABLE 0x0b
#define PORT_E_PARAM_CONFIG           0x0c
#define PORT_E_PARAM_INVALID_MODE     0x0d
#define PORT_E_MODE_UNCHANGEABLE      0x0e
#define PORT_E_UNINIT                 0x0f

#define PORT_INIT_ID                    0x00
#define PORT_SET_PIN_DIRECTION_ID       0x01
#define PORT_REFRESH_PORT_DIRECTION_ID  0x02
#define PORT_GET_VERSION_INFO_ID        0x03
#define PORT_SET_PIN_MODE_ID            0x04

typedef enum
{
    PORT_PIN_IN = 0, 
    PORT_PIN_OUT
} Port_PinDirectionType;

typedef uint8_t  Port_PinType;
typedef uint32_t Port_PinModeType;

typedef struct _Port_ConfigType
{
    Port_PinType          portType;
    Port_PinModeType      portModeType;
    Port_PinDirectionType directionType;
} Port_ConfigType;

void Port_Init(const Port_ConfigType *configType);

#if 0
void Port_SetPinDirection(Port_PinType pin, Port_PinDirectionType direction);
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

void Port_RefreshPortDirection(void);


#endif