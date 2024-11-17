#pragma once

#ifdef _WIN32
    #ifdef CUSTOM_DLL_EXPORTS
        #define CUSTOM_DLL_API __declspec(dllexport)
    #else
        #define CUSTOM_DLL_API __declspec(dllimport)
    #endif
#else
    #define CUSTOM_DLL_API __attribute__((visibility("default")))
#endif

#include <cmath>

#include "ImageProcessor.hpp"

class CUSTOM_DLL_API CustomDll : public ImageProcessor
{
public:
    CustomDll() {};
    CustomDll(const std::string& prefix) : ImageProcessor(prefix) {};
    ~CustomDll() {};

    bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) override;
};