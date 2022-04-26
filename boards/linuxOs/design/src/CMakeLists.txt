add_library(ncboard STATIC createBoard.c)

target_include_directories(ncboard PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(ncboard PUBLIC /usr/include/libxml2)