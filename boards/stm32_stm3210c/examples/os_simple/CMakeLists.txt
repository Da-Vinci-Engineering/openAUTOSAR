#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

#set(CMAKE_C_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*")


add_library (stm32examples ${PROJECT_SOURCE_DIR}/system/kernel/asm_offset.c )

set (CMAKE_C_FLAGS "-mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -std=gnu99 -MMD -Wall -fno-strict-aliasing	-fno-builtin" )

target_include_directories(stm32examples PUBLIC ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/arm ${PROJECT_SOURCE_DIR}/system/kernel/include)

add_custom_command(TARGET stm32examples 
                   PRE_BUILD 
                   COMMAND ${CMAKE_C_COMPILER} ARGS -mthumb -mcpu=cortex-m3 -mfix-cortex-m3-ldrd -ggdb -ffunction-sections -g -O0 -std=gnu99 -MMD -Wall -fno-strict-aliasing -fno-builtin -I${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c/examples/os_simple/config -I${PROJECT_SOURCE_DIR}/include -I${PROJECT_SOURCE_DIR}/include/arm -I${PROJECT_SOURCE_DIR}/system/kernel/include -S ${PROJECT_SOURCE_DIR}/system/kernel/asm_offset.c
                   VERBATIM)

#                   COMMAND gawk ARGS '/.*define/ { print $1 " " $2 " " gensub("#","","g",$3) } arch_offset.s' 
#target_include_directories(LogAndTraceDaemon PUBLIC ${PROJECT_SOURCE_DIR}/libComm/include)

#target_link_libraries(LogAndTraceDaemon LINK_PUBLIC Diag Comm)
