add_library (Debug STATIC src/Det.c)

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_DET -DUSE_ECUM -DUSE_KERNEL -DUSE_MCU -DCFG_ARM -DCFG_ARM_CM3 -DCFG_BRD_STM32_STM3210C -DCFG_STM32_CL -DUSE_RAMLOG -DSELECT_OS_CONSOLE=TTY_NONE -DSELECT_CONSOLE=RAMLOG")

target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )


