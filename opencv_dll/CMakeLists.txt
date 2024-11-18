cmake_minimum_required(VERSION 3.10)

project(opencv_dll)

add_library(opencv_dll SHARED
        OpencvDll.cpp
)

target_include_directories(opencv_dll PUBLIC
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/processor
)

target_link_libraries(opencv_dll PRIVATE
        ${OpenCV_LIBS}
        processor
)