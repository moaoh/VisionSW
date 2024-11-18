cmake_minimum_required(VERSION 3.10)

project(processor)

add_library(processor SHARED
        ImageObject.cpp
        ImageProcessor.cpp
        GetConfigProcessor.cpp
        processor.cpp
        Logger.cpp
)

target_include_directories(processor PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(processor PRIVATE
        ${OpenCV_LIBS}
)