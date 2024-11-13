#ifndef OPENCV_DLL_HPP_
#define OPENCV_DLL_HPP_

#ifdef _WIN32
    #ifdef OPENCV_DLL_EXPORTS
        #define OPENCV_DLL_API __declspec(dllexport)
    #else
        #define OPENCV_DLL_API __declspec(dllimport)
    #endif
#else
    #define OPENCV_DLL_API __attribute__((visibility("default")))  // Mac/Linux에서 사용할 export
#endif

#include "ImageObject.hpp"
#include "ImageProcessor.hpp"

class OPENCV_DLL_API OpencvDll : public ImageProcessor
{
public:
    OpencvDll() {};
    ~OpencvDll() {};

    bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize);
};

#endif // OPENCV_DLL_HPP_