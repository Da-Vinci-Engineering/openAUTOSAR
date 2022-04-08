#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (Eep STATIC src/Eep.c
                        )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_DET")

target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Eep/include )
#target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/diagnostic/Dem/include )
#target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
#target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
#target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include)
#target_include_directories(EEepa PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel)