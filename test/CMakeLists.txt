cmake_minimum_required(VERSION 3.8)

add_executable(new_test scheduler_test.cpp)

target_link_libraries(new_test PUBLIC gtest_main)

add_test(NAME new_test COMMAND new_test)