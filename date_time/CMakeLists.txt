cmake_minimum_required(VERSION 3.31)
project(date_time CXX)

set(CMAKE_TOOLCHAIN_FILE "/Users/sh704/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
find_package(Boost 1.88.0 REQUIRED COMPONENTS date_time)
set(CMAKE_CXX_STANDARD 14)

add_executable(date_time main.cpp)

target_link_libraries(date_time PRIVATE Boost::date_time)