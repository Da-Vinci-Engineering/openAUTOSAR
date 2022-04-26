#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library ( CanTp STATIC src/CanTp.c
                               src/CanTp_Cfg.c
    )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanTp/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/diagnostic/Dcm/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Can/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include )
    target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
                
endif()