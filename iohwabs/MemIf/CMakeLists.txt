#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string (APPEND CMAKE_C_FLAGS " -DUSE_EA -DUSE_FEE")
    add_library (MemIf STATIC src/MemIf.c
                        )
    target_include_directories(MemIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(MemIf PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
endif()