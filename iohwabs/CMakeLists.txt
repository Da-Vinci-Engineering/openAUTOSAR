#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#    add_subdirectory(Fee)
#    add_subdirectory(MemIf)
#    add_subdirectory(Ea)
#    add_subdirectory(WdgIf)
endif()