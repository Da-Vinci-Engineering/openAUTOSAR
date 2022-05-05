set (CMAKE_C_FLAGS "-g -O0 -std=gnu99 -Wall")

add_executable(blinker src/Blinker.c
                       src/IoHwAb.c
                       src/Tasks.c
                )

target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/examples/led_rte/config)

target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/system/EcuM/include)
target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include)

target_link_libraries(blinker PUBLIC Kernel)