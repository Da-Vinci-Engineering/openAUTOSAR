#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -DSTM32F10X_CL -DCFG_ARM_CM3")
    add_library (Crc STATIC src/Crc_16.c 
                            src/Crc_32.c 
               )
    target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/system/Crc/include)
    target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/include )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_library (Crc STATIC src/Crc_16.c 
                            src/Crc_32.c 
                )
    target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/system/Crc/include)
    target_include_directories(Crc PUBLIC ${PROJECT_SOURCE_DIR}/include )
endif()

