#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

add_library (Debug STATIC src/Det.c)

if(CMAKE_CROSSCOMPILING)
    target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
endif()


target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )


