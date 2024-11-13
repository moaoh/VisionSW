#include <iostream>

#include <opencv2/opencv.hpp>

#include "OpencvDll.hpp"
#include "CustomDll.hpp"

int main() {
    // 이미지 파일 경로
    std::string imagePath = "../images/test.jpeg";

    cv::Mat image = cv::imread(imagePath);
    if (image.empty()) {
        std::cout << "이미지를 읽을 수 없습니다!" << std::endl;
        return -1;
    }

    ImageObject src(image.cols, image.rows);
    src.fromMat(image);

    ImageObject dst(image.cols, image.rows);

    OpencvDll opencvDllObject;
    CustomDll customDllObject;
    bool opencvSuccess = opencvDllObject.ImageBlur(&src, &dst, 5);
    bool customSuccess = customDllObject.ImageBlur(&src, &dst, 5);

    if (!opencvSuccess) {
        std::cout << "opencv : 블러 처리 실패!" << std::endl;
        return -1;
    }
    if (!customSuccess) {
        std::cout << "custom : 블러 처리 실패!" << std::endl;
        return -1;
    }

    return 0;
}