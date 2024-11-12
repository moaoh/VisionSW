cmake_minimum_required(VERSION 3.10)
project(AiV-VisionSW)

set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/opencv/build")

find_package(OpenCV REQUIRED)

add_executable(AiV-VisionSW
        src/main.cpp
)

target_include_directories(AiV-VisionSW PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(AiV-VisionSW PRIVATE ${OpenCV_LIBS})