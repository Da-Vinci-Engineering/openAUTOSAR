#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library ( Com STATIC src/Com_Com.c
                        src/Com_misc.c
                        src/Com_Sched.c
                        src/Com.c
            )
set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_PDUR")
target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/Com/include )
target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/com_simple/config )
