#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library (rte STATIC src/rte.c
    )
endif()

target_include_directories(rte PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(rte PUBLIC ${PROJECT_SOURCE_DIR}/rte/include )