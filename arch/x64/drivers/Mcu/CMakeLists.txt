#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(NOT CMAKE_CROSSCOMPILING)
    add_library (Mcu STATIC src/Mcu.c 
                )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/drivers/Mcu/include )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
endif()