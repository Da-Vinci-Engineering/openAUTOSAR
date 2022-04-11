#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (NvM STATIC src/NvM.c
                        src/Nvm_ServiceComponent.c
                        )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_KERNEL -DUSE_MCU -DUSE_DET -DCFG_ARM -DCFG_ARM_CM3 -DCFG_BRD_STM32_STM3210C -DCFG_STM32_CL")

target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/memory/NvM/include )
target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/system/Crc/include)
target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include)
target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include)
target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel)
