#include "CustomDll.hpp"

/*
src : 입력영상
dst : 출력영상
kernelSize : 블러링 커널 크기 ( 블러의 강도 )
*/
bool CustomDll::ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) {
    std::cout << "CustomDll::ImageBlur" << std::endl;
    /*
        직접구현
     */
    return true;
}