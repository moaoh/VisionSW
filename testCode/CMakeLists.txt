cmake_minimum_required(VERSION 3.3)

project(testCode)

find_package(OpenCV REQUIRED)

add_executable(testCode
        main.cpp
)

target_compile_definitions(testCode PRIVATE TEST_IMAGE_PATH="${TEST_IMAGE_PATH}")

target_include_directories(testCode PRIVATE
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/image_processor
        ${CMAKE_SOURCE_DIR}/opencv_dll
        ${CMAKE_SOURCE_DIR}/custom_dll
)

target_link_libraries(testCode PRIVATE
        ${OpenCV_LIBS}
        image_processor
        opencv_dll
        custom_dll
)