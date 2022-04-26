#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library (Crc STATIC src/Crc_16.c 
                            src/Crc_32.c 
                )
    target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/system/Crc/include)
    target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/include )
endif()

