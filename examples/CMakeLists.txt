#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

if(CMAKE_CROSSCOMPILING)
    add_subdirectory(os_simple)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_subdirectory(rte_simple)
endif()
