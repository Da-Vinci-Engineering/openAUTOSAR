#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

#set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*")

add_library (common cirq_buffer.c printf.c xtoa.c ramlog.c tcf/streams.c)

target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/clib/)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include/)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/common/tcf)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include/arm/) 
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel/) 
target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config/)
