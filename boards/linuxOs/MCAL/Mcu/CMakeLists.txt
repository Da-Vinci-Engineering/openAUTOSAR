#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

    add_library (Mcu STATIC src/Mcu.c 
                )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Mcu/include )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
    target_include_directories(Mcu PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
