cmake_minimum_required(VERSION 3.8)

project(test LANGUAGES CXX)

set(TARGET test)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(${TARGET} test.cpp ../parser.cpp)

target_link_libraries(${TARGET} Boost::unit_test_framework)