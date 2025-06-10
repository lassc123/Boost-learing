cmake_minimum_required(VERSION 3.31)
project(25_6_10 CXX)

find_package(Boost 1.88.0 REQUIRED COMPONENTS timer)

set(CMAKE_CXX_STANDARD 17)

add_executable(25_6_10 main.cpp)

target_link_libraries(25_6_10 PRIVATE Boost::timer)
