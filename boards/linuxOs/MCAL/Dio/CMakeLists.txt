#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library ( Dio STATIC src/Dio.c
                )
                target_include_directories(Dio PUBLIC ${PROJECT_SOURCE_DIR}/include )
                target_include_directories(Dio PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Dio/include )
                target_include_directories(Dio PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Os/include )
