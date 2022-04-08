#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (Crc STATIC src/Crc_16.c 
                        src/Crc_32.c 
            )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -DSTM32F10X_CL -DCFG_ARM_CM3")
target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/system/Crc/include)
#target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
#target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
#target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/include )
#target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
#target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/include/arm/arm_cm3/)
#target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)
#target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include)