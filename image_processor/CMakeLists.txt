# shared_dll/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(image_processor)

find_package(OpenCV REQUIRED)

add_library(image_processor SHARED
        ImageObject.cpp
        ImageProcessor.cpp
)

target_include_directories(image_processor PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(image_processor PRIVATE
        ${OpenCV_LIBS}
)