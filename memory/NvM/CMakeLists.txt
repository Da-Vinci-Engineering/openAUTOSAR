#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

    add_library (NvM STATIC src/NvM.c
                            src/Nvm_ServiceComponent.c
                )

    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/memory/NvM/include )
    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/MemIf/include )
    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/system/Crc/include)
    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include)
    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include)
    target_include_directories(NvM PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/kernel/include)

endif()