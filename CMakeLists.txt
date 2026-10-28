cmake_minimum_required(VERSION 3.24)
project(miniweb LANGUAGES CXX)

# 使用标准 C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 导出编译数据库，供 clangd 读取
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 公共编译配置
add_library(miniweb_options INTERFACE)

target_compile_options(miniweb_options INTERFACE
    -Wall
    -Wextra
    -Wpedantic
)

# 查找 Boost 头文件
# 使用系统安装的 Boost 时，可以不设置 BOOST_ROOT
set(BOOST_ROOT "" CACHE PATH "Optional Boost root directory")

find_path(BOOST_INCLUDE_DIR
    NAMES boost/version.hpp
    HINTS "${BOOST_ROOT}"
    REQUIRED
)

# 查找系统线程支持
find_package(Threads REQUIRED)

target_include_directories(miniweb_options SYSTEM INTERFACE
    "${BOOST_INCLUDE_DIR}"
)

target_link_libraries(miniweb_options INTERFACE
    Threads::Threads
)

# 第四章的应用实现
add_library(miniweb_core STATIC
    src/app.cpp
    src/server.cpp
    src/session.cpp
    src/router.cpp
)

# 项目自己的头文件
target_include_directories(miniweb_core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(miniweb_core PUBLIC
    miniweb_options
)

# 程序入口
add_executable(miniweb
    src/main.cpp
)

target_link_libraries(miniweb PRIVATE
    miniweb_core
)