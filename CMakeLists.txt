cmake_minimum_required(VERSION 3.8)
project(BuildTool)

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)
add_subdirectory(json)

add_library(BuildTool_lib
    src/actions/ArLinkAction.cpp
    src/actions/GccObjAction.cpp
    src/actions/GccPchAction.cpp
    src/actions/ObjAction.cpp
    src/artifact_parser.cpp
    src/build_params.cpp
    src/build_tool.cpp
    src/file_checker.cpp
    src/scheduler.cpp)

add_executable(BuildTool src/main.cpp)

target_include_directories(BuildTool_lib PUBLIC inc)
target_link_libraries(BuildTool_lib PUBLIC nlohmann_json)
target_link_libraries(BuildTool PUBLIC BuildTool_lib)

enable_testing()
add_executable(new_test
    test/build_tool_test.cpp
    test/parser_test.cpp)
target_link_libraries(new_test PUBLIC 
    BuildTool_lib
    gtest_main)
add_test(NAME new_test COMMAND new_test)