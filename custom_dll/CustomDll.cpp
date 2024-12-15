#include "CustomDll.hpp"

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
    int threadCount = std::thread::hardware_concurrency(); // system thread max size

    const std::vector<unsigned char>& inputBuffer = src->getBuffer();
    std::vector<unsigned char> outputBuffer(imageWidth * imageHeight * src->getChannels());

    int kernelRadius = kernelSize / 2;

    auto blurTask = [&](int startRow, int endRow) {
        for (int centerY = startRow; centerY < endRow; centerY++) {
            for (int centerX = 0; centerX < imageWidth; centerX++) {
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
                int pixelIndex = centerY * imageWidth + centerX;
        		outputBuffer[pixelIndex] = std::round(pixelSum / (kernelSize * kernelSize));
            }
        }
    };

    std::vector<std::thread> threads;
    int rowsPerThread = imageHeight / threadCount;
	int startRow, endRow;
    for (int i = 0; i < threadCount; ++i) {
        startRow = i * rowsPerThread;
        if (i == threadCount - 1) endRow = imageHeight;
        else endRow = startRow + rowsPerThread;
        threads.emplace_back(blurTask, startRow, endRow);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    dst->setBuffer(outputBuffer);
    dst->setWidth(imageWidth);
    dst->setHeight(imageHeight);
    dst->setChannels(src->getChannels());

    return true;
}