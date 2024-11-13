cmake_minimum_required(VERSION 3.3)

project(custom_dll)

find_package(OpenCV REQUIRED)

add_library(custom_dll SHARED
        CustomDll.cpp
)

target_include_directories(custom_dll PUBLIC
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/image_processor
)

target_link_libraries(custom_dll PRIVATE
        ${OpenCV_LIBS}
        image_processor
)