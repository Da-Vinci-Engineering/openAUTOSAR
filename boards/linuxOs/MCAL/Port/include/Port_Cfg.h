/********************************************************************
* (C) DaVinci Engineering GmbH 2022
********************************************************************/

#ifndef PORTCFG_H_
#define PORTCFG_H_

#define PORT_VERSION_INFO_API STD_OFF
#define PORT_DEV_ERROR_DETECT STD_OFF

#define PORT_A_PIN_0
#define PORT_B_PIN_0

#define GPIOA_BASE 0x00001000
#define GPIOB_BASE 0x00002000
#define GPIOC_BASE 0x00004000

typedef struct _Port_ConfigType
{
    uint8_t padCnt;
} Port_ConfigType;

#endif // PORTCFG_H_