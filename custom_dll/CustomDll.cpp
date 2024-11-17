#include "CustomDll.hpp"

#include <Logger.hpp>

/*
src : 입력영상
dst : 출력영상
kernelSize : 블러링 커널 크기 ( 블러의 강도 )
*/
bool CustomDll::ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) {
    if(!src || !dst) {
      return false;
    }

    int imageWidth = src->getWidth();
    int imageHeight = src->getHeight();

    std::vector<unsigned char> inputBuffer = src->getBuffer();
    std::vector<unsigned char> outputBuffer(imageWidth * imageHeight * src->getChannels());

    int kernelRadius = kernelSize / 2;

    for (int pixelIndex = 0; pixelIndex < inputBuffer.size(); pixelIndex++) {
        int centerY = pixelIndex / imageWidth;
        int centerX = pixelIndex % imageWidth;
        double pixelSum = 0;
        for (int offsetY = -kernelRadius; offsetY <= kernelRadius; offsetY++) {
            for (int offsetX = -kernelRadius; offsetX <= kernelRadius; offsetX++) {
              int neighborY = centerY + offsetY;
              int neighborX = centerX + offsetX;

              if (neighborY < 0) {
                neighborY = -neighborY;
              } else if (neighborY >= imageHeight) {
                neighborY = 2 * imageHeight - neighborY - 2;
              }
              if (neighborX < 0) {
                neighborX = -neighborX;
              } else if (neighborX >= imageWidth) {
                neighborX = 2 * imageWidth - neighborX - 2;
              }
              int neighborIndex = neighborY * imageWidth + neighborX;
              pixelSum += inputBuffer[neighborIndex];
            }
        }
        outputBuffer[pixelIndex] = std::round(pixelSum / (kernelSize * kernelSize));
    }
    dst->setBuffer(outputBuffer);
    dst->setWidth(imageWidth);
    dst->setHeight(imageHeight);
    dst->setChannels(src->getChannels());

    return true;
}