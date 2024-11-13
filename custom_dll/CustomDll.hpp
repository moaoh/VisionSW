#ifndef CUSTOM_DLL_HPP_
#define CUSTOM_DLL_HPP_

#ifdef _WIN32
    #ifdef CUSTOM_DLL_EXPORTS
        #define CUSTOM_DLL_API __declspec(dllexport)
    #else
        #define CUSTOM_DLL_API __declspec(dllimport)
    #endif
#else
    #define CUSTOM_DLL_API __attribute__((visibility("default")))  // Mac/Linux에서 사용할 export
#endif

#include "ImageObject.hpp"
#include "ImageProcessor.hpp"

class CUSTOM_DLL_API CustomDll : public ImageProcessor
{
public:
    CustomDll() {};
    ~CustomDll() {};

    bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize);
};

#endif // CUSTOM_DLL_HPP_