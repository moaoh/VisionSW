#include "CustomDll.hpp"

/*
src : 입력영상
dst : 출력영상
kernelSize : 블러링 커널 크기 ( 블러의 강도 )
*/
bool CustomDll::ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) {

    int imageWidth = src->getWidth();
    int imageHeight = src->getHeight();

    std::vector<unsigned char> inputBuffer = src->getBuffer();
    std::vector<unsigned char> outputBuffer(imageWidth * imageHeight * src->getChannels());

    int kernelRadius = kernelSize / 2;

    for (int pixelIndex = 0; pixelIndex < inputBuffer.size(); pixelIndex++) {
        int centerY = pixelIndex / imageWidth;
        int centerX = pixelIndex % imageWidth;
        int pixelSum = 0;
        for (int offsetY = -kernelRadius; offsetY <= kernelRadius; offsetY++) {
            for (int offsetX = -kernelRadius; offsetX <= kernelRadius; offsetX++) {
                int neighborY = centerY + offsetY;
                int neighborX = centerX + offsetX;

                if (0 <= neighborY && neighborY < imageHeight && 0 <= neighborX && neighborX < imageWidth) {
                    int neighborIndex = neighborY * imageWidth + neighborX;
                    pixelSum += inputBuffer[neighborIndex];
                } else {
                    pixelSum += inputBuffer[pixelIndex];
                }
            }
        }
        outputBuffer[pixelIndex] = pixelSum / (kernelSize * kernelSize);
    }
    dst->setBuffer(outputBuffer);
    dst->setWidth(imageWidth);
    dst->setHeight(imageHeight);
    dst->setChannels(src->getChannels());

    return true;
}