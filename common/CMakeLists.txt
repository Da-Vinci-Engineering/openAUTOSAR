#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

add_library (common STATIC src/cirq_buffer.c 
                        src/printf.c    
                        src/xtoa.c 
                        src/ramlog.c 
                        tcf/streams.c)

target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/clib/)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include/)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/common/tcf)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include/arm/) 
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel/) 
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config/)
