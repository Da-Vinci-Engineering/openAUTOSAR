#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DUSE_PDUR -DCFG_ARM_CM3 -DUSE_COM -DUSE_DET")
    add_library ( LinIf STATIC src/LinIf.c
                )

    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinSM/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_PDUR -DUSE_COM -DUSE_DET")
    add_library ( LinIf STATIC src/LinIf.c
                )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinSM/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
endif()