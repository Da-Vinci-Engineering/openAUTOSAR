/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

#ifndef FLS_CONFIGTYPES_H_
#define FLS_CONFIGTYPES_H_

#include <stdint.h>

// Used as address offset from the configured flash base address to access a certain
// flash memory area.
/**************************************************
 * Moved from fls.h to prevent board dependency
 * (C) DaVinci Engineering GmbH 2022
 *************************************************/ 
typedef uint32_t Fls_AddressType;

// Specifies the number of bytes to read/write/erase/compare
//
// Note!
// Shall be the same type as Fls_AddressType because of
// arithmetic operations. Size depends on target platform and
// flash device.
/**************************************************
 * Moved from fls.h to prevent board dependency
 * (C) DaVinci Engineering GmbH 2022
 *************************************************/ 
typedef uint32_t Fls_LengthType;

#if (USE_FLS_INFO==STD_ON)

typedef struct Flash {
    uint32_t size;
    uint32_t sectCnt;
    uint32_t bankSize;
    uint32_t regBase;
    uint32_t sectAddr[FLASH_MAX_SECTORS+1];
    uint16_t addrSpace[FLASH_MAX_SECTORS+1];
} FlashType;


#else
typedef struct {
  Fls_LengthType FlsNumberOfSectors;
  Fls_LengthType FlsPageSize;
  Fls_LengthType FlsSectorSize;
  Fls_AddressType FlsSectorStartaddress;
} Fls_SectorType;
#endif


struct Flash;

typedef struct {
	void (*FlsAcErase)();					/* NO SUPPORT */
	void (*FlsAcWrite)();					/* NO SUPPORT */
	// FlsCallCycle N/A in core.
	void (*FlsJobEndNotification)();
	void (*FlsJobErrorNotification)();
	uint32_t FlsMaxReadFastMode;				/* NO SUPPORT */
	uint32_t FlsMaxReadNormalMode;			/* NO SUPPORT */
	uint32_t FlsMaxWriteFastMode;				/* NO SUPPORT */
	uint32_t FlsMaxWriteNormalMode;			/* NO SUPPORT */
	uint32_t FlsProtection;					/* NO SUPPORT */
#if (USE_FLS_INFO==STD_ON)
	const struct Flash *FlsInfo;
#else
	const Fls_SectorType *FlsSectorList;
	const uint32 FlsSectorListSize;			/* NO SUPPORT */
#endif
} Fls_ConfigSetType;

typedef Fls_ConfigSetType Fls_ConfigType;

extern const Fls_ConfigSetType FlsConfigSet[];


#endif /* FLS_CONFIGTYPES_H_ */
