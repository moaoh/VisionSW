cmake_minimum_required(VERSION 3.10)

project(opencv_dll)

find_package(OpenCV REQUIRED)

add_library(opencv_dll SHARED
        opencv_dll.cpp
)

target_include_directories(opencv_dll PUBLIC
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/image_processor
)

target_link_libraries(opencv_dll PRIVATE
        ${OpenCV_LIBS}
        image_processor
)