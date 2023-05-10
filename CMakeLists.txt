cmake_minimum_required(VERSION 3.8)
project(BuildTool)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)

add_library(BuildTool_lib
    src/action.cpp
    src/scheduler.cpp)

target_include_directories(BuildTool_lib PUBLIC inc)

enable_testing()
add_executable(new_test 
    test/scheduler_test.cpp)
target_link_libraries(new_test PUBLIC 
    BuildTool_lib
    gtest_main)
add_test(NAME new_test COMMAND new_test)