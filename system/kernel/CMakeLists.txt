#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_MCU")
add_library (Kernel STATIC src/event.c 
            src/init.c 
            src/task.c
            src/resource.c
            src/alarm.c
            src/sched_table.c
            src/counter.c
            src/isr.c
            src/os_arctest.c
            src/application.c
            src/asm_offset.c
            )

target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/include/arm )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
string(APPEND CMAKE_C_FLAGS " -DUSE_MCU")
add_library (Kernel STATIC src/event.c 
            src/init.c 
            src/task.c
            src/resource.c
            src/alarm.c
            src/sched_table.c
            src/counter.c
            #src/isr.c
            src/os_arctest.c
            #src/application.c
            src/asm_offset.c
            )

target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/include )
#target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/include/arm )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
target_include_directories(Kernel PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)

endif()