#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string (APPEND CMAKE_C_FLAGS " -DUSE_DET")
    add_library (Fee STATIC ${PROJECT_SOURCE_DIR}/iohwabs/Fee/src/Fee.c
                            src/Fee_Cfg.c
                            )

    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Fee/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/iohwabs/Fee/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include)
    target_include_directories(Fee PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Fls/include)
endif()