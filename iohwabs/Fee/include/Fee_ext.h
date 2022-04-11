/********************************************************************
 * (C) DaVinci Engineering GmbH 2022
 *******************************************************************/
#ifndef FEE_EXT_H_
#define FEE_EXT_H_

#include "Std_Types.h"
#include "Fls_ConfigTypes.h"

extern Std_ReturnType Fls_Erase(	Fls_AddressType   TargetAddress,
                        Fls_LengthType    Length );


Std_ReturnType Fls_Write (    Fls_AddressType   TargetAddress,
                        const uint8         *SourceAddressPtr,
                        Fls_LengthType    Length );

//#if ( FLS_CANCEL_API == STD_ON )
void 				Fls_Cancel( void );
//#endif

//#if ( FLS_GET_STATUS_API == STD_ON )
MemIf_StatusType 	Fls_GetStatus(	void );
//#endif

//#if ( 1 )
MemIf_JobResultType Fls_GetJobResult( void );
//#endif

Std_ReturnType Fls_Read (	Fls_AddressType SourceAddress,
              uint8 *TargetAddressPtr,
              Fls_LengthType Length );

#endif // FEE_EXT_H_


