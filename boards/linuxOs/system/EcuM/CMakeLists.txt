#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_MCU -DUSE_RTE")
    add_library (EcuM STATIC ${PROJECT_SOURCE_DIR}/system/EcuM/src/EcuM.c 
                            ${PROJECT_SOURCE_DIR}/system/EcuM/src/EcuM_Main.c 
                            ${PROJECT_SOURCE_DIR}/system/EcuM/src/EcuM_Callout_Stubs.c 
                            ${PROJECT_SOURCE_DIR}/system/EcuM/src/EcuM_ServiceComponent.c 
                )

    target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/system/EcuM/include)
    target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/system/EcuM/include)
    target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Os/include )
    target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)
    target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include)
endif()