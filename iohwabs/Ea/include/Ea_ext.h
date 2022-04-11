/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 *******************************************************************/
#ifndef EA_EXT_H_
#define EA_EXT_H_

#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Eep_Cfg.h"

//extern void Eep_Init( const Eep_ConfigType *ConfigPtr );
extern Std_ReturnType Eep_Erase(	Eep_AddressType   EepromAddress,
                  			Eep_LengthType    Length );


extern Std_ReturnType Eep_Write (    Eep_AddressType   EepromAddress,
			                  const uint8         *SourceAddressPtr,
			                  Eep_LengthType    Length );

extern  void Eep_Cancel( void );
extern MemIf_StatusType 	Eep_GetStatus(	void );
extern MemIf_JobResultType Eep_GetJobResult( void );

//void Eep_MainFunction( void );

extern Std_ReturnType Eep_Read (	Eep_AddressType EepromAddress,
							uint8 *TargetAddressPtr,
							Eep_LengthType Length );

extern Std_ReturnType Eep_Compare( Eep_AddressType EepromAddress,
							uint8 *TargetAddressPtr,
							Eep_LengthType Length );

//void Eep_SetMode( MemIf_ModeType Mode );


#endif // EA_EXT_H_


