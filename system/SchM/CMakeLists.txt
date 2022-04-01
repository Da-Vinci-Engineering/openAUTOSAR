#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (SchM STATIC src/SchM.c 
            )

#-DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_MCU
set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -fno-builtin")
target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/system/SchM/include)
target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(SchM PUBLIC ${PROJECT_SOURCE_DIR}/boards/generic )
