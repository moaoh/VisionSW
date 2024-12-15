cmake_minimum_required(VERSION 3.10)
project(visionSW)

set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/opencv/build)
find_package(OpenCV REQUIRED NO_DEFAULT_PATH)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(processor)
add_subdirectory(opencv_dll)
add_subdirectory(custom_dll)
add_subdirectory(test_code)