set (CMAKE_C_FLAGS "-g -O0 -std=gnu99 -Wall")

add_executable(testncboard main.c)

find_package(LibXml2 REQUIRED)

target_include_directories(testncboard PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(testncboard PUBLIC ${LIBXML2_INCLUDE_DIR})

target_link_libraries(testncboard PUBLIC ncboard ${LIBXML2_LIBRARIES} m z lzma icuuc form ncurses)