cmake_minimum_required(VERSION 3.30)
project(glbasics)

set(CMAKE_CXX_STANDARD 17)

add_library(glbasics STATIC
        Display.cpp
        glad.c
        glinclude.h
        init.cpp
        glbasics.h
        keys.h)
find_package(glfw3 REQUIRED)
target_link_libraries(glbasics glfw)

add_executable(test
        main.cpp)
target_link_libraries(test glbasics)