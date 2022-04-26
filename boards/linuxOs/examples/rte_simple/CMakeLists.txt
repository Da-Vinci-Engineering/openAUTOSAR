#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

set (CMAKE_C_FLAGS "-g -O0 -std=gnu99 -Wall")
add_executable (rte_simple 
                    #Calculator.c
                    #Logger.c
                    #Logger2.c
                    #Tester.c
                    rte_simple.c
                    system_hooks.c    
                )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/communication/CAN/CanIf/include )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/drivers/Mcu/include )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/drivers/Dio/include )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/system/EcuM/include )
target_include_directories(rte_simple PUBLIC ${PROJECT_SOURCE_DIR}/include )

