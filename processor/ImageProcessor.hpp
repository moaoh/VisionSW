#pragma once

#ifdef _WIN32
    #ifdef IMAGE_PROCESSOR_EXPORTS
        #define IMAGE_PROCESSOR_API __declspec(dllexport)
    #else
        #define IMAGE_PROCESSOR_API __declspec(dllimport)
    #endif
#else
    #define IMAGE_PROCESSOR_API __attribute__((visibility("default")))  // Mac/Linux에서 사용할 export
#endif

#include <iostream>
#include <fstream>

#include "ImageObject.hpp"

class IMAGE_PROCESSOR_API ImageProcessor
{
public:
    ImageProcessor();
    ImageProcessor(const std::string& prefix);
    ~ImageProcessor();

    virtual bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) = 0;

    std::string getPrefix() const;
    void setPrefix(const std::string& prefix);
private:
    std::string _prefix;
};