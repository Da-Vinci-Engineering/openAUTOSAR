#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

add_library (archArmArmCm3 STATIC kernel/startup_stm32f10x.s kernel/arch_offset.c kernel/arch.c kernel/core_cm3.c kernel/irq.c 
            kernel/sys_tick.c)

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections")
target_include_directories(archArmArmCm3 PUBLIC ${PROJECT_SOURCE_DIR}/kernel )
target_include_directories(archArmArmCm3 PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(archArmArmCm3 PUBLIC ${PROJECT_SOURCE_DIR}/include/arm )
target_include_directories(archArmArmCm3 PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(archArmArmCm3 PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)