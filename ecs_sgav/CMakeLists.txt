cmake_minimum_required(VERSION 3.5)

project(ecs_sgav LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src/")

# Include files .h and cpp
file (GLOB_RECURSE src_files "${src_dir}*.hpp" "${src_dir}*.cpp")

add_executable(ecs_sgav ${src_files})
