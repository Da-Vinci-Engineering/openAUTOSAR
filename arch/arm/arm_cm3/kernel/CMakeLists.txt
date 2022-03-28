#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
enable_language(ASM)

set_source_files_properties(startup_stm32f10x.s LANGUAGE ASM)
set_source_files_properties(arch_krn.s LANGUAGE ASM)

add_library (armCm3 STATIC 
            startup_stm32f10x.s 
            arch_krn.s
            arch_offset.c
            Cpu.c
            arch.c 
            core_cm3.c 
            irq.c 
            sys_tick.c )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -gdwarf -g2 -DSTM32F10X_CL -DCFG_ARM_CM3")
target_include_directories(armCm3 PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(armCm3 PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(armCm3 PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(armCm3 PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(armCm3 PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)