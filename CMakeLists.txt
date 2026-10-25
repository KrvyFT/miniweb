cmake_minimum_required(VERSION 3.24)
project(miniweb LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(miniweb_options INTERFACE)

target_compile_options(miniweb_options INTERFACE
    -Wall
    -Wextra
    -Wpedantic
)

add_library(miniweb_core STATIC
    src/app.cpp
    src/demo.cpp
)

target_include_directories(miniweb_core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(miniweb_core PUBLIC miniweb_options)

add_executable(miniweb src/main.cpp)

target_link_libraries(miniweb PRIVATE miniweb_core)