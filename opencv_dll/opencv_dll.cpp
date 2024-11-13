#include "opencv_dll.hpp"

/*
src : 입력영상
dst : 출력영상
kernelSize : 블러링 커널 크기 ( 블러의 강도 )
*/
bool Opencv_dll::ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) {
    cv::Mat image = src->toMat();
    cv::Mat outputImage = dst->toMat();

    if(image.empty()) {
        return false;
    }

    for (int ksize = 3; ksize <= 11; ksize += 2) {
        cv::blur(image, outputImage, cv::Size(ksize, ksize));

        cv::String text = cv::format("Mean : %d, %d", ksize, ksize);

        putText(outputImage, text, cv::Point(10, 30), cv::FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(255), 1, cv::LINE_AA);

        cv::imshow("dst", outputImage);
        cv::waitKey();
    }
    return true;
}
