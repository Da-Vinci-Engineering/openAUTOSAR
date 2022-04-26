#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    string(APPEND CMAKE_C_FLAGS " -DUSE_PDUR -DUSE_COM -DUSE_DET")
    add_library ( LinIf STATIC src/LinIf.c
                )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinIf/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/LIN/LinSM/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/system/ComM/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/debug/Det/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/PDURouter/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/communication/ComServices/Com/include )
    target_include_directories(LinIf PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/config/include )
endif()