#include "ImageObject.hpp"

ImageObject::ImageObject() {}

ImageObject::ImageObject(const cv::Mat& mat) {
    this->fromMat(mat);
}

cv::Mat ImageObject::toMat() const {
  if (_buffer.empty() || _height <= 0 || _width <= 0) {
    return cv::Mat();
  }

  int cvType;
  if (_channels == 1) {
    cvType = CV_8UC1;  // 1 흑백
  } else if (_channels == 3) {
    cvType = CV_8UC3;  // 3 RGB
  } else if (_channels == 4) {
    cvType = CV_8UC4;  // 4 RGBA
  } else {
    return cv::Mat();
  }

  return cv::Mat(_height, _width, cvType, const_cast<unsigned char*>(_buffer.data())).clone();
}

void ImageObject::fromMat(const cv::Mat& mat) {
    _width = mat.cols;
    _height = mat.rows;
    _channels = mat.channels();
    _buffer.resize(_width * _height * _channels);
    std::copy(mat.data, mat.data + mat.total() * mat.elemSize(), _buffer.begin());
}

int ImageObject::getWidth() const {
    return _width;
}

int ImageObject::getHeight() const {
    return _height;
}

void ImageObject::setWidth(int w) {
    _width = w;
}
void ImageObject::setHeight(int h) {
    _height = h;
}

int ImageObject::getChannels() const {
    return _channels;
}
void ImageObject::setChannels(int c) {
    _channels = c;
}
std::vector<unsigned char> ImageObject::getBuffer() const {
    return _buffer;
}

void ImageObject::setBuffer(const std::vector<unsigned char>& buffer) {
    _buffer = buffer;
}