#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string (APPEND CMAKE_C_FLAGS " -DUSE_EA -DUSE_FEE")
    add_library (WdgIf STATIC ${PROJECT_SOURCE_DIR}/iohwabs/WdgIf/src/WdgIf.c
                )
    target_include_directories(WdgIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(WdgIf PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/WdgIf/include )
    target_include_directories(WdgIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/iohwabs/WdgIf/include )
    target_include_directories(WdgIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Wdg/include )
endif()