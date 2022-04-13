#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (Ea STATIC src/Ea.c
                        )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_DET -DUSE_ECUM -DUSE_KERNEL -DUSE_MCU -DCFG_ARM -DCFG_ARM_CM3 -DCFG_BRD_STM32_STM3210C -DCFG_STM32_CL -DUSE_RAMLOG -DSELECT_OS_CONSOLE=TTY_NONE -DSELECT_CONSOLE=RAMLOG")

target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Ea/include )
target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Eep/include)
target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include)
target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel)