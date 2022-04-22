/*
* Configuration of module: Mcu (Mcu_Cfg.h)
*
* Created by:              
* Copyright: 2022 DaVinci Engineering GmbH 
*
* Configured for:          LinuxOs
*
* Module vendor:           DaVinci
* Version:                 0.2.0
*/



#ifndef MCU_CFG_C_
#define MCU_CFG_C_

#include "Mcu.h"



const Mcu_ClockSettingConfigType Mcu_ClockSettingConfigData[] =
{
  {
    .McuClockReferencePointFrequency = 25000000UL,
    .Pll1    = 9,
    .Pll2    = 8,
    .Pll3    = 0,
  },
};

const Mcu_PerClockConfigType McuPerClockConfigData =
{ 
	.AHBClocksEnable = RCC_AHBPeriph_DMA1 | RCC_AHBPeriph_ETH_MAC | RCC_AHBPeriph_ETH_MAC_Tx | RCC_AHBPeriph_ETH_MAC_Rx,
	.APB1ClocksEnable = RCC_APB1Periph_TIM2 | RCC_APB1Periph_CAN1,
	.APB2ClocksEnable = RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO
};

const Mcu_ConfigType McuConfigData[] = {
  {
	.McuClockSrcFailureNotification = 0,
	.McuRamSectors = MCU_NBR_OF_RAM_SECTIONS,
	.McuClockSettings = 1,
	.McuDefaultClockSettings = 0,
	.McuClockSettingConfig = &Mcu_ClockSettingConfigData[0],
	.McuRamSectorSettingConfig = NULL,
  }
};

#endif /*MCU_CFG_C_*/