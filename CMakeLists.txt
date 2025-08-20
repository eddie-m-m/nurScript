cmake_minimum_required(VERSION 3.12)
project(nurScript CXX)

# Set the C++ standard to 20
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(nurScript src/main.cpp)
