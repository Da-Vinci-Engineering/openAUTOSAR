#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)

    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library (Dcm STATIC src/Dcm.c
                            src/Dcm_Dsd.c
                            src/Dcm_Dsl.c
                            src/Dcm_Dsp.c
                        )
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include)
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/drivers/Mcu/include)
endif()

target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/diagnostic/Dcm/include )
target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
