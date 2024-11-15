#include "ImageObject.hpp"

ImageObject::ImageObject(const cv::Mat& mat) {
    this->fromMat(mat);
}

cv::Mat ImageObject::toMat() const {
    return cv::Mat(_height, _width, CV_8UC1, const_cast<unsigned char*>(_buffer.data())).clone();
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