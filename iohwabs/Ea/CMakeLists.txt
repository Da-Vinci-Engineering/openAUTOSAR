#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string (APPEND CMAKE_C_FLAGS "  -DUSE_DET -DUSE_ECUM -DUSE_KERNEL -DUSE_MCU")
    add_library (Ea STATIC src/Ea.c
                )                  
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Ea/include )
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Eep/include)
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Wdg/include)
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include)
    target_include_directories(Ea PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include)
endif()