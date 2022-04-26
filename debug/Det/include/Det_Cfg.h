/*
* Configuration of module: Det (Det_Cfg.h)
*
* Created by:              
* Copyright: 2022 DaVinci Engineering GmbH 
*
* Configured for:          LinuxOs
*
* Module vendor:           DaVinci
* Version:                 0.2.0
*/

/*
 * Development Error Tracer driver
 *
 * Specification: Autosar v2.0.1, Final
 *
 */
#ifndef DET_CFG_H
#define DET_CFG_H 

#define DET_ENABLE_CALLBACKS STD_ON  // Enable to use callback on errors
#define DET_USE_RAMLOG       STD_ON  // Enable to log DET errors to ramlog
#define DET_WRAP_RAMLOG      STD_ON  // The ramlog wraps around when reaching the end
#define DET_USE_STDERR       STD_OFF // Enable to get DET errors on stderr
#define DET_DEINIT_API       STD_OFF // Enable/Disable the Det_DeInit function
#define DET_RAMLOG_SIZE         (16) // Number of entries in ramlog
#define DET_NUMBER_OF_CALLBACKS (5)  // Number of callbacks

#endif /* DET_CFG_H */
