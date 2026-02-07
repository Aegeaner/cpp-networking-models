cmake_minimum_required(VERSION 3.16)
project(cpp_networking_models LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add custom cmake module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Common library
add_subdirectory(common)

# Networking Models
add_subdirectory(1-blocking)
add_subdirectory(2-thread_pool)
add_subdirectory(3-asio_callback)
add_subdirectory(4-asio_coroutine)
add_subdirectory(5-libevent)
add_subdirectory(6-seastar)

message(STATUS "Build system for C++ Networking Models configured.")
