#include "ImageObject.hpp"

cv::Mat ImageObject::toMat() const {
    return cv::Mat(_height, _width, CV_8UC3, const_cast<unsigned char*>(_buffer.data()));
}

void ImageObject::fromMat(const cv::Mat& mat) {
    _width = mat.cols;
    _height = mat.rows;
    _buffer.resize(_width * _height * 3);  // RGB
    std::memcpy(_buffer.data(), mat.data, _buffer.size());
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