#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library ( CanTp STATIC src/CanTp.c
                           src/CanTp_Cfg.c
            )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_PDUR")
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanTp/include )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
#target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
#target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/include )
#target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
#target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/CanDriver/include )
target_include_directories(CanTp PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM )
