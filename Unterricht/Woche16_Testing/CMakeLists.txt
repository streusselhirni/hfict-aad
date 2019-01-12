cmake_minimum_required(VERSION 3.13)
project(Woche16_Testing)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Woche16_Testing src/main.cpp src/Utils.cpp src/Utils.h)
add_executable(Test test/Utils.cpp src/Utils.h src/Utils.cpp)