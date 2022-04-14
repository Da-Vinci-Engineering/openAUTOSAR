# the name of the target operating system
set(CMAKE_SYSTEM_NAME Generic)

# which compilers to use for C and C++
set(C_COMPILER_INSTALLATION /opt/gcc-arm-11.2-2022.02-x86_64-arm-none-eabi)
set(CMAKE_C_COMPILER   ${C_COMPILER_INSTALLATION}/bin/arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER ${C_COMPILER_INSTALLATION}/bin/arm-none-eabi-gcc)
set(CMAKE_LINKER ${C_COMPILER_INSTALLATION}/bin/arm-none-eabi-ld)

set(CMAKE_TRY_COMPILE_TARGET_TYPE         STATIC_LIBRARY)
# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  ${C_COMPILER_INSTALLATION} )

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
