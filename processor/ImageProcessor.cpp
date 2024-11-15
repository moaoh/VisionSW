#include "ImageProcessor.hpp"

ImageProcessor::ImageProcessor() {}

ImageProcessor::ImageProcessor(const std::string& prefix) {
    _prefix = prefix;
}

ImageProcessor::~ImageProcessor() {}

std::string ImageProcessor::getPrefix() const {
    return _prefix;
}

void ImageProcessor::setPrefix(const std::string& prefix) {
    _prefix = prefix;
}