cmake_minimum_required(VERSION 3.10)

project(custom_dll)

add_library(custom_dll SHARED
        CustomDll.cpp
)

target_include_directories(custom_dll PUBLIC
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/processor
)

target_link_libraries(custom_dll PRIVATE
        ${OpenCV_LIBS}
        processor
)