#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (WdgIf STATIC src/WdgIf.c
                        )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -c -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin -DSTM32F10X_CL -DUSE_EA -DUSE_FEE")

target_include_directories(WdgIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(WdgIf PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/WdgIf/include )
target_include_directories(WdgIf PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Wdg/include )
