#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library (common STATIC src/cirq_buffer.c
                )
    target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include/)
    target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include)
endif()

