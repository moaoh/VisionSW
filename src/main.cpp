#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
  std::cout << "OpenCV version: " << CV_VERSION << std::endl;

  // 이미지 생성 및 저장 테스트
  cv::Mat image = cv::Mat::zeros(100, 100, CV_8UC3);
  cv::circle(image, cv::Point(50, 50), 40, cv::Scalar(255, 0, 0), -1);
  cv::imwrite("test.jpg", image);

  std::cout << "Image created and saved as test.jpg" << std::endl;

  return 0;
}