#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
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

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_PDUR")
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanTp/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/diagnostic/Dcm/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
#target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
#target_include_directories(PDURouter PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/CanDriver/include )
