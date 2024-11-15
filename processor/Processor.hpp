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

#include <iostream>
#include <fstream>
#include <filesystem>

#include "GetConfigProcessor.hpp"
#include "ImageProcessor.hpp"


class Processor
{
public:
    Processor(GetConfigProcessor& config, ImageProcessor& imageProcessor);
    ~Processor() {};

    std::string getProcessingMode();
    void setProcessingMode(std::string processingMode);
private:
    std::string _processorMode;

    bool validateImage(const cv::Mat* src);
};