add_library(ncboard STATIC createBoard.c)

find_package(LibXml2 REQUIRED)
target_include_directories(ncboard PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(ncboard PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/design/include)
target_include_directories(ncboard PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Port/include)
target_include_directories(ncboard PUBLIC ${LIBXML2_INCLUDE_DIR})