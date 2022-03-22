#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
cmake_minimum_required (VERSION 3.7.2)
project(openAUTOSAR)

#set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*")
set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_DET -DUSE_ECUM -DUSE_KERNEL -DUSE_MCU -DCFG_ARM -DCFG_ARM_CM3 -DCFG_BRD_STM32_STM3210C -DCFG_STM32_CL -DUSE_RAMLOG -DSELECT_OS_CONSOLE=TTY_NONE -DSELECT_CONSOLE=RAMLOG")

add_subdirectory(clib)
add_subdirectory(common)
add_subdirectory(arch/arm/arm_cm3)
add_subdirectory(boards/stm32_stm3210c/examples/os_simple)
add_subdirectory(system)
add_subdirectory(examples)
add_subdirectory(diagnostic)
add_subdirectory(arch/arm/arm_cm3/scripts)
