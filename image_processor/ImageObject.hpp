#ifndef IMAGE_OBJECT_HPP_
#define IMAGE_OBJECT_HPP_

/*
실제 pixel 값이 포함된 buffer,
영상 크기(width, height) 정보가 포함된 image object를 구현한다.
구현한 image object는 OpenCV library의 cv::Mat 과 호환이 되어야 한다.
*/

#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

class ImageObject
{
public:
  ImageObject();
  ImageObject(const cv::Mat& mat);
  ImageObject(int w, int h) : _width(w), _height(h), _buffer(w * h * 3) {}
  ~ImageObject() {}

  cv::Mat toMat() const;
  void fromMat(const cv::Mat& mat);

  int getWidth() const;
  int getHeight() const;
  void setWidth(int w);
  void setHeight(int h);

private:
  int _width;
  int _height;
  std::vector<unsigned char> _buffer;
};

#endif // IMAGE_OBJECT_HPP_