/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 ********************************************************************/


#ifndef IOHWAB_TYPES_H_
#define IOHWAB_TYPES_H_

#include <Std_Types.h>

/* Digital levels */
typedef uint8  IoHwAb_LevelType;

/* Analog values base type */
typedef sint32 IoHwAb_AnalogValueType;

//typedef sint32 IoHwAb_ChannelType;

#if !defined(CFG_IOHWAB_USE_SERVICE_COMPONENT)
//typedef sint32 IoHwAb_SignalType;
#endif

/* Duty cycle type (per mille) */
typedef uint32 IoHwAb_DutyType;
#define IOHWAB_DUTY_MIN		   0u		/*   0% */
#define IOHWAB_DUTY_MAX		1000u		/* 100% */

/* Frequency type (Hz) */
typedef uint32 IoHwAb_FrequencyType;

/* ISO14229, IoControl */
#define	IOHWAB_RETURNCONTROLTOECU 	0
#define	IOHWAB_RESETTODEFAULT		1
#define	IOHWAB_FREEZECURRENTSTATE	2
#define	IOHWAB_SHORTTERMADJUST		3

/* Freescale qADC have 12-bit ADC resolution bit 14-bit result */
#define ADC_MAX_VALUE				16384

#define IOHWAB_LOW			STD_LOW
#define IOHWAB_HIGH			STD_HIGH

/* Quality */
typedef enum {
	IOHWAB_INIVAL,	/* Value not available */
	IOHWAB_ERR,		/* Electrical diagnosic set */
	IOHWAB_BAD,
	IOHWAB_GOOD,
} IoHwAb_QualityType;

typedef struct {
	IoHwAb_QualityType quality;
} IoHwAb_StatusType;

#endif /* IOHWAB_TYPES_H_ */
