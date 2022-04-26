#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_COM -DUSE_PDUR")
    add_library ( CanIf STATIC src/CanIf.c
                                src/CanIf_Cfg.c
                )

    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/Com/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
#    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Can/include )
            
endif()