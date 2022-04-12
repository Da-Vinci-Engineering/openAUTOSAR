#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library ( Adc STATIC src/Adc_Internal.c
            )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3")
target_include_directories(Adc PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Adc PUBLIC ${PROJECT_SOURCE_DIR}/drivers/Adc/include )
target_include_directories(Adc PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(Adc PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
