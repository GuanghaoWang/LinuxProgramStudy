set(PROJETC_NAME seek_io)
project(seek_io)

cmake_minimum_required(VERSION 2.8)

add_subdirectory(lib)
include_directories(lib)
aux_source_directory(./src DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})
target_link_libraries(${PROJECT_NAME} libcommon)
