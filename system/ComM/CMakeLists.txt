#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (ComM STATIC src/ComM.c 
            )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_MCU")
target_include_directories(ComM PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include)
target_include_directories(ComM PUBLIC ${PROJECT_SOURCE_DIR}/include )
