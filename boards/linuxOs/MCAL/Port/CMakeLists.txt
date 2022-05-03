#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library ( Port STATIC src/Port.c
                )
target_include_directories(Port PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Port PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Port/include )
target_include_directories(Port PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
#target_include_directories(Port PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Os/include )
