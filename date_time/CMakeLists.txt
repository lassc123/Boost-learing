cmake_minimum_required(VERSION 3.31)
project(data_time CXX)

find_package(Boost 1.88.0 REQUIRED COMPONENTS date_time)
set(CMAKE_CXX_STANDARD 14)

add_executable(data_time main.cpp)

target_link_libraries(data_time PRIVATE Boost::date_time)