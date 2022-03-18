#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

add_library (Mcu STATIC Mcu.c 
            STM32F10x_StdPeriph_Driver/src)

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -DSTM32F10X_CL -DCFG_ARM_CM3")
target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/ )
target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/include/arm )
target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/include/arm/arm_cm3 )
target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)