#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_MCU -DUSE_ECUM")
    add_library (SchM STATIC src/SchM.c 
                )

    target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include)
    target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
    target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
    target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Os/include )
    target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/system/EcuM/include)

endif()