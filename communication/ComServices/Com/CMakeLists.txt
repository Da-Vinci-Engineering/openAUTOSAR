#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
            add_library ( Com STATIC src/Com_Com.c
                        src/Com_misc.c
                        src/Com_Sched.c
                        src/Com.c
                        )
            target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/Com/include )
            target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/include )
            target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
            target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/arch/x64/kernel/include )
            target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
            target_include_directories(Com PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/include )
endif()

