#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_subdirectory(Crc)
    add_subdirectory(Nm)
    add_subdirectory(kernel)
    add_subdirectory(ComM)
    add_subdirectory(SchM)
    add_subdirectory(WdgM)
endif()