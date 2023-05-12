cmake_minimum_required(VERSION 3.8)
project(BuildTool)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)
add_subdirectory(json)

add_library(BuildTool_lib
    src/action.cpp
    src/artifact_parser.cpp
    src/scheduler.cpp)

target_include_directories(BuildTool_lib PUBLIC inc)
target_link_libraries(BuildTool_lib PUBLIC nlohmann_json)

enable_testing()
add_executable(new_test
    test/parser_test.cpp
    test/scheduler_test.cpp)
target_link_libraries(new_test PUBLIC 
    BuildTool_lib
    gtest_main)
add_test(NAME new_test COMMAND new_test)