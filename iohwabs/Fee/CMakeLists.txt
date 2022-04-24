#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_DET")
    add_library (Fee STATIC src/Fee.c
                            src/Fee_Cfg.c
                            )

    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Fee/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include)
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/drivers/Fls/include)
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string (APPEND CMAKE_C_FLAGS " -DUSE_DET")
    add_library (Fee STATIC src/Fee.c
                            src/Fee_Cfg.c
                            )

    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Fee/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include)
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/drivers/Fls/include)
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
endif()