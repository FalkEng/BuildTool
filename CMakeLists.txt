cmake_minimum_required(VERSION 3.1)
project(BuildTool)

add_library(${PROJECT_NAME}_lib 
    src/task.cpp
    src/scheduler.cpp
    src/worker.cpp)

target_include_directories(${PROJECT_NAME}_lib PRIVATE inc)
