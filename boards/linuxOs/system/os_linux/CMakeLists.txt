#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_MCU ")
    add_library (os_linux STATIC src/os_linos.c 
                )

    #target_include_directories(os_linux PUBLIC ${PROJECT_SOURCE_DIR}/system/os_linux/include)
    target_include_directories(os_linux PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/system/os_linux/include)
    #target_include_directories(os_linux PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(os_linux PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Os/include )
    target_include_directories(os_linux PUBLIC ${PROJECT_SOURCE_DIR}/include )
    #target_include_directories(os_linux PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)
    #target_include_directories(os_linux PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include)
endif()