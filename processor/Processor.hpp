#pragma once

#ifdef _WIN32
    #ifdef PROCESSOR_EXPORTS
        #define PROCESSOR_API __declspec(dllexport)
    #else
        #define PROCESSOR_API __declspec(dllimport)
    #endif
#else
    #define PROCESSOR_API __attribute__((visibility("default")))  // Mac/Linux에서 사용할 export
#endif

#include <fstream>
#include <chrono>

#include "GetConfigProcessor.hpp"
#include "ImageProcessor.hpp"
#include "Logger.hpp"

class Processor
{
public:
    Processor(ImageProcessor& imageProcessor);
    ~Processor() = default;

    cv::Mat run(const std::string& imagePath, const std::string& outputPath, int kernelSize);
private:
    ImageProcessor& _imageProcessor;

    bool isBlackAndWhite(const cv::Mat* src);
    size_t getMemoryUsage();
    void logMemoryAndTime(const std::string& prefix,
        size_t memoryBefore, size_t memoryAfter,
        const std::chrono::high_resolution_clock::time_point& start,
        const std::chrono::high_resolution_clock::time_point& end);
};