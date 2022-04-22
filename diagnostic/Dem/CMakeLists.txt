#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    add_library (Dem STATIC src/Dem.c
                )

    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/diagnostic/Dem/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/memory/NvM/include )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config )
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/include)
    target_include_directories(Dem PUBLIC ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/kernel)

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