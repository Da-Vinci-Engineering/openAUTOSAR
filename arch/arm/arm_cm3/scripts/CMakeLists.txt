#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/

add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/linkscript_gcc.lcf
    COMMAND ${CMAKE_C_COMPILER}
            ARGS -E -P -x assembler-with-cpp -DSTM32F10X_CL -DUSE_DET -DUSE_ECUM -DUSE_KERNEL -DUSE_MCU -DCFG_ARM 
                 -DCFG_ARM_CM3 -DCFG_BRD_STM32_STM3210C -DCFG_STM32_CL
                 -o ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/linkscript_gcc.lcf
                 -I ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts
                 -I ${PROJECT_SOURCE_DIR}/boards/stm32_stm3210c
                 ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/linkscript_gcc.ldf
    )

add_custom_target( os_simple.elf ALL
    COMMAND ${CMAKE_LINKER}
    -Map ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/os_simple.map   -T ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/linkscript_gcc.lcf
    -o ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/os_simple.elf
    -L${C_COMPILER_INSTALLATION}/arm-none-eabi/lib/thumb/v7-m/nofp
    -L${C_COMPILER_INSTALLATION}/lib/gcc/arm-none-eabi/10.3.1/thumb/v7-m/nofp
    -L${PROJECT_SOURCE_DIR}/build/arch/arm/arm_cm3/drivers/Mcu
    -L${PROJECT_SOURCE_DIR}/build/arch/arm/arm_cm3/kernel
    -L${PROJECT_SOURCE_DIR}/build/boards/stm32_stm3210c/examples/os_simple
    -L${PROJECT_SOURCE_DIR}/build/clib
    -L${PROJECT_SOURCE_DIR}/build/common
    -L${PROJECT_SOURCE_DIR}/build/diagnostic/Dcm
    -L${PROJECT_SOURCE_DIR}/build/examples/os_simple
    -L${PROJECT_SOURCE_DIR}/build/system/EcuM
    -L${PROJECT_SOURCE_DIR}/build/system/kernel
    --start-group
    -lexampleCfg -lclib -lcommon -lDcm -los_simple
    -lEcuM -lKernel -lMcu -larmCm3
    -lgcc -lc  
    --end-group
    DEPENDS ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/linkscript_gcc.lcf
)

add_custom_target( momory_footprint ALL
    COMMAND gawk --non-decimal-data 
    -f ${PROJECT_SOURCE_DIR}/scripts/memory_footprint_gcc.awk
    ${PROJECT_SOURCE_DIR}/arch/arm/arm_cm3/scripts/os_simple.map
    DEPENDS os_simple.elf
)
