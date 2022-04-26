#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library (Dem STATIC src/Dem.c
    )

    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/diagnostic/Dem/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/memory/NvM/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include)

endif()