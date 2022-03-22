#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

#set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*")

add_library (clib  ${PROJECT_SOURCE_DIR}/clib/clib.c ${PROJECT_SOURCE_DIR}/clib/strtok_r.c ${PROJECT_SOURCE_DIR}/clib/clib_port.c)

target_include_directories(clib PUBLIC ${PROJECT_SOURCE_DIR}/clib ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/arm/ ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel/ ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config/)
