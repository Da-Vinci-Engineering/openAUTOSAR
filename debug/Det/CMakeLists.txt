#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

add_library (Debug STATIC src/Det.c)

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
endif()


target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Debug PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )


