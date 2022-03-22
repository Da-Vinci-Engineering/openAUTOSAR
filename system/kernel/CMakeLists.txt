#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (Kernel STATIC event.c 
            init.c 
            task.c
            resource.c
            alarm.c
            sched_table.c
            counter.c
            isr.c
            os_arctest.c
            application.c
            asm_offset.c
            )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_MCU")
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/include/arm )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)