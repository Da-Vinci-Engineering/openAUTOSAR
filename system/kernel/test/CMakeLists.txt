#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(CMAKE_C_FLAGS "-g -O0 -std=gnu99 -Wall -DUSE_MCU")
add_executable (blinky 
            ../src/event.c 
            ../src/init.c 
            ${PROJECT_SOURCE_DIR}/boards/linuxOs/examples/led_rte/config/Cpu.c
            ../src/task.c
            ../src/resource.c
            ../src/alarm.c
            ../src/sched_table.c
            ../src/counter.c
            ../src/isr.c
            ../src/os_arctest.c
            ../src/application.c
            ../src/asm_offset.c
            )

target_link_libraries(blinky PUBLIC Kernel EcuM os_linux)
#target_include_directories(blinky PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
target_include_directories(blinky PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(blinky PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/system/os_linux/include )
#target_include_directories(blinky PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)

endif()