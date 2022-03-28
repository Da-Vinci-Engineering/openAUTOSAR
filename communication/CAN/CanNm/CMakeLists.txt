#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library ( CanNm STATIC src/CanNm.c
            )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_PDUR")
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanNm/include )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
#target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
#target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
#target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
#target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
#target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/CanDriver/include )



target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/CanDriver/include )
