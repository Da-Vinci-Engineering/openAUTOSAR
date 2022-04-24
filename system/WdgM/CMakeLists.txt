#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -DSTM32F10X_CL -DCFG_ARM_CM3 -DUSE_MCU") 
    add_library (WdgM STATIC src/WdgM.c 
                            src/WdgM_ServiceComponent.c
                )

    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/system/WdgM/include)
    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/WdgIf/include)
    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/include )

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_MCU -DUSE_ECUM")

    add_library (WdgM STATIC src/WdgM.c 
                             src/WdgM_ServiceComponent.c
                )

    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/system/WdgM/include)
    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/WdgIf/include)
    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/include )
endif()