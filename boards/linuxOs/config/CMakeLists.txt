#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

#set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*")

if(NOT CMAKE_CROSSCOMPILING)
    add_library (exampleCfg src/EcuM_PBcfg.c
                            src/Mcu_Cfg.c
)

endif()

target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/include )
target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/drivers/Mcu/include )
target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include)
target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include)
target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/system/EcuM/include) 
target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include) 
target_include_directories(exampleCfg PUBLIC ${PROJECT_SOURCE_DIR}/system/kernel/include) 
