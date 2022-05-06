set (CMAKE_C_FLAGS "-g -O0 -std=gnu99 -Wall -DUSE_DIO -DUSE_DET")

add_executable(blinker src/Blinker.c
                       src/Rte_Blinker.c
                       src/Rte.c
                       src/IoHwAb_ServiceComponent.c
                       src/IoHwAb_Digital.c
#                       src/IoHwAb.c
#                       src/Tasks.c
                )

target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/examples/led_rte/config)
target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/examples/led_rte/include)

target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/system/EcuM/include)
target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include)
target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Dio/include)
target_include_directories(blinker PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include)

target_link_libraries(blinker PUBLIC Kernel)