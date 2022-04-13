#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (rte STATIC src/rte.c
                        )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_KERNEL -DUSE_MCU -DUSE_DET -DCFG_ARM -DCFG_ARM_CM3 -DCFG_BRD_STM32_STM3210C -DCFG_STM32_CL")

target_include_directories(rte PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(rte PUBLIC ${PROJECT_SOURCE_DIR}/rte/include )