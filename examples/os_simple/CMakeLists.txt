#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -DSTM32F10X_CL -DCFG_ARM_CM3")
    add_library (os_simple STATIC system_hooks.c 
                                  os_simple.c)
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/drivers/Mcu/include )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/include/arm )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/include )
    
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set (CMAKE_C_FLAGS "-g -O0 -c -std=gnu99 -Wall")
    add_library (os_simple STATIC system_hooks.c 
                                  os_simple.c)
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/drivers/Mcu/include )
    target_include_directories(os_simple PUBLIC ${PROJECT_SOURCE_DIR}/include )

endif()

