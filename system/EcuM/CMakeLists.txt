#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (EcuM STATIC src/EcuM.c 
            src/EcuM_Main.c 
            src/EcuM_Callout_Stubs.c 
            src/EcuM_ServiceComponent.c 
            )

#-fno-builtin -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_MCU
set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_MCU")
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/system/EcuM/include)
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include)
target_include_directories(EcuM PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include)