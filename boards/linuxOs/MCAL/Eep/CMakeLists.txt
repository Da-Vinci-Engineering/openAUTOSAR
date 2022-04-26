#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library (Eep STATIC src/Eep.c
                        )

target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_include_directories(Eep PUBLIC ${PROJECT_SOURCE_DIR}/iohwabs/Eep/include )
