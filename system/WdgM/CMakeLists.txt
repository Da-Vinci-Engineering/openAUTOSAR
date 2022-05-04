#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_MCU -DUSE_ECUM")

    add_library (WdgM STATIC src/WdgM.c 
                             src/WdgM_ServiceComponent.c
                )

    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/system/WdgM/include)
    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/WdgIf/include)
    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(WdgM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/iohwabs/WdgIf/include )
endif()