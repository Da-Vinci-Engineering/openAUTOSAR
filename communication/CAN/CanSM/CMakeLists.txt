#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library ( CanSM STATIC src/CanSM.c
                               src/CanSM_Cfg.c
    )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanSM/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanTp/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/Com/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Can/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include )
    target_include_directories(CanSM PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
                
endif()