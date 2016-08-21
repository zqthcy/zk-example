cmake_minimum_required(VERSION 3.2)

project(zk-example)

aux_source_directory(./src SOURCE_FILES)
add_executable(zk-example ${SOURCE_FILES})
target_link_libraries(zk-example -lzookeeper_mt)
