#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_COM -USE_PDUR -DUSE_DET")
    add_library ( LinSM STATIC src/LinSM.c
                )

    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinSM/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/mpc5602b_xpc560b/examples/lin_simple/config )

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library ( LinSM STATIC src/LinSM.c
                )

    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinSM/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/drivers/Mcu/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
endif()
