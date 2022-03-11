#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*")

find_library(gcc)
add_library (stm32examples config/Mcu_Cfg.c )

target_include_directories(stm32examples PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config)
#target_include_directories(LogAndTraceDaemon PUBLIC ${PROJECT_SOURCE_DIR}/libComm/include)

#target_link_libraries(LogAndTraceDaemon LINK_PUBLIC Diag Comm)
