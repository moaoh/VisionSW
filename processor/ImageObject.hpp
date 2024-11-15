#pragma once

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
  ~ImageObject() {}

  cv::Mat toMat() const;
  void fromMat(const cv::Mat& mat);

  int getWidth() const;
  void setWidth(int w);
  int getHeight() const;
  void setHeight(int h);
  int getChannels() const;
  void setChannels(int c);
  std::vector<unsigned char> getBuffer() const;
  void setBuffer(const std::vector<unsigned char>& buffer);
  std::string getImageName() const;
  void setImageName(const std::string& name);
  std::string getOutputPath();
  void setOutputPath(const std::string& path);

private:
  int _width;
  int _height;
  int _channels;
  std::vector<unsigned char> _buffer;
  std::string _imageName;
  std::string _outputPath;

};