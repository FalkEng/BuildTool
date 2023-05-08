cmake_minimum_required(VERSION 3.8)
project(BuildTool)

enable_testing()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
add_subdirectory(googletest)
add_subdirectory(test)