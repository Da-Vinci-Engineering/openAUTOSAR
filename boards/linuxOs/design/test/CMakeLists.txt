add_executable(testncboard main.c)

target_include_directories(testncboard PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(testncboard PUBLIC /usr/include/libxml2)

target_link_libraries(testncboard PUBLIC ncboard /usr/lib/x86_64-linux-gnu/libxml2.a m z lzma icuuc)