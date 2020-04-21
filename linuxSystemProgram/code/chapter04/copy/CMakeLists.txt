project(copy)

cmake_minimum_required(VERSION 2.8)

add_subdirectory(lib)
include_directories(lib)
aux_source_directory(./src DIR_SRCS)

add_executable(copy ${DIR_SRCS})
target_link_libraries(copy libcommon)
