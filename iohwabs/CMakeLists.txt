#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    add_subdirectory(Fee)
    add_subdirectory(MemIf)
    add_subdirectory(Ea)
    add_subdirectory(WdgIf)
#
# Hardware-related modules
#
#add_subdirectory(Eep)
#add_subdirectory(Wdg)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_subdirectory(Fee)
    add_subdirectory(MemIf)
    add_subdirectory(Ea)
    add_subdirectory(WdgIf)
endif()