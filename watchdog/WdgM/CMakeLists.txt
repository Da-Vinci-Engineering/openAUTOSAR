#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (WdgM STATIC src/Dcm.c
                        src/Dcm_Dsd.c
                        src/Dcm_Dsl.c
                        src/Dcm_Dsp.c
                        )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_KERNEL -DUSE_MCU -DCFG_ARM -DCFG_ARM_CM3 -DCFG_BRD_STM32_STM3210C -DCFG_STM32_CL")

#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/watchdog/WdgM/include )
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/include/arm )
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include)
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel)
#target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include)