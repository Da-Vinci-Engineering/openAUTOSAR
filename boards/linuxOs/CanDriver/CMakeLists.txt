#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

#set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*")


add_library (canDriver config/EcuM_PBcfg.c
                        config/Mcu_Cfg.c
                        config/Os_Cfg.c
            )
#-DCFG_ARM_CM3 -DSTM32F10X_CL
set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -std=gnu99 -MMD -Wall -fno-strict-aliasing -fno-builtin ")

#target_include_directories(canDriver PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/arm ${PROJECT_SOURCE_DIR}/system/kernel/include ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel ${PROJECT_SOURCE_DIR}/include/arm/arm_cm3/ ${PROJECT_SOURCE_DIR}/system/EcuM)
