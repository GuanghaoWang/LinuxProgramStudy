project(large_file)

cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME large_file)
add_subdirectory(lib)
include_directories(lib)
aux_source_directory(./src DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})
target_link_libraries(${PROJECT_NAME} libcommon)
