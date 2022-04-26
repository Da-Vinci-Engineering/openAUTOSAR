#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library ( LinSM STATIC src/LinSM.c
                )

    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinSM/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/Com/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(LinSM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
endif()
