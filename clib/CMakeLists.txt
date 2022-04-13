#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

add_library (clib  STATIC src/clib.c 
                          src/strtok_r.c 
                          src/clib_port.c
                          )

target_include_directories(clib PUBLIC ${PROJECT_SOURCE_DIR}/clib/include) 
target_include_directories(clib PUBLIC ${PROJECT_SOURCE_DIR}/include) 
target_include_directories(clib PUBLIC ${PROJECT_SOURCE_DIR}/include/arm/) 
target_include_directories(clib PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel/) 
target_include_directories(clib PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config/)
