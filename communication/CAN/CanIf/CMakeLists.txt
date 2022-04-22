#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    add_library ( CanIf STATIC src/CanIf.c
                                src/CanIf_Cfg.c
                )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_COM -DUSE_PDUR")
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/CanDriver/include )

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_COM -DUSE_PDUR")
    add_library ( CanIf STATIC src/CanIf.c
                                src/CanIf_Cfg.c
                )

    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/drivers/Mcu/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
    target_include_directories(CanIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/CanDriver/include )
            
endif()