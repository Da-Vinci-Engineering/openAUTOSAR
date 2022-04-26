#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_MCU")
    add_library (ComM STATIC src/ComM.c 
                )

    target_include_directories(ComM PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include)
    target_include_directories(ComM PUBLIC ${PROJECT_SOURCE_DIR}/include )
endif()