cmake_minimum_required(VERSION 3.10)
project(AiV-VisionSW)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(image_processor)
add_subdirectory(opencv_dll)
add_subdirectory(custom_dll)
add_subdirectory(testCode)