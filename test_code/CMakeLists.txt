cmake_minimum_required(VERSION 3.3)

project(test_code)

find_package(OpenCV REQUIRED)

add_executable(test_code
        main.cpp
)

target_compile_definitions(test_code PRIVATE TEST_IMAGE_PATH="${TEST_IMAGE_PATH}")

target_include_directories(test_code PRIVATE
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/opencv_dll
        ${CMAKE_SOURCE_DIR}/custom_dll
        ${CMAKE_SOURCE_DIR}/processor
)

target_link_libraries(test_code PRIVATE
        ${OpenCV_LIBS}
        opencv_dll
        custom_dll
        processor
)

add_custom_command(TARGET test_code POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:test_code> ${CMAKE_SOURCE_DIR}/bin
        COMMENT "Copying testCode executable to bin directory"
)