#include "ImageObject.hpp"

ImageObject::ImageObject(const cv::Mat& mat) {
    _width = mat.cols;
    _height = mat.rows;
    _buffer.resize(_width * _height * 3);  // RGB
    std::memcpy(_buffer.data(), mat.data, _buffer.size());
}

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

std::string ImageObject::getImageName() const {
    return _imageName;
}

void ImageObject::setImageName(const std::string& name) {
    _imageName = name;
}

std::string ImageObject::getOutputPath() {
    return _outputPath;
}
void ImageObject::setOutputPath(const std::string& path) {
    _outputPath = path;
}