#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

add_library ( PDURouter STATIC  src/PduR.c
                            src/PduR_CanIf.c
                            src/PduR_CanTp.c
                            src/PduR_Com.c
                            src/PduR_Dcm.c
                            src/PduR_J1939Tp.c
                            src/PduR_LinIf.c
                            src/PduR_Logic.c
                            src/PduR_Routing.c
                            src/PduR_SoAd.c
            )

            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/Com/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanTp/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/diagnostic/Dcm/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Can/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
            target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
            
endif()