cmake_minimum_required(VERSION 3.8)

project(test LANGUAGES CXX)

set(TARGET test)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(${TARGET} test.cpp ../parser.cpp)

target_link_libraries(${TARGET} Boost::unit_test_framework)