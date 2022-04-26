#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library ( CanNm STATIC src/CanNm.c
    )

    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanNm/include )
    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/system/Nm/include )
    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
    target_include_directories(CanNm PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Can/include )

endif()
