cmake_minimum_required(VERSION 3.8)
project(Cartoonifyimages)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Cartoonify.cpp Cartoonify.h)
add_executable(Cartoonifyimages ${SOURCE_FILES})

find_package(OpenCV 4.1.2 REQUIRED)

target_link_libraries(Cartoonifyimages ${OpenCV_LIBS})