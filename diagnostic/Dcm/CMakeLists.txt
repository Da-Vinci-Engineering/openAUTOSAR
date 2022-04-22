#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)

    add_library (Dcm STATIC src/Dcm.c
                        src/Dcm_Dsd.c
                        src/Dcm_Dsl.c
                        src/Dcm_Dsp.c
                        )

    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include)
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel)
    target_include_directories(Dcm PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include)
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
