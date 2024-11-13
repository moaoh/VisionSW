#include <iostream>

#include <opencv2/opencv.hpp>

#include "opencv_dll.hpp"

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

    Opencv_dll opencvObject;
    bool success = opencvObject.ImageBlur(&src, &dst, 5);
    if (!success) {
        std::cout << "블러 처리 실패!" << std::endl;
        return -1;
    }

    return 0;
}