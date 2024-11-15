#include "OpencvDll.hpp"

/*
src : 입력영상
dst : 출력영상
kernelSize : 블러링 커널 크기 ( 블러의 강도 )
*/
bool OpencvDll::ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) {
    cv::Mat image = src->toMat();
    cv::Mat outputImage = dst->toMat();
    cv::blur(image, outputImage, cv::Size(kernelSize, kernelSize));
    dst->fromMat(outputImage);
    return true;
}
