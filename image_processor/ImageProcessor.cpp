#include "ImageProcessor.hpp"

/*
1. 이미지 경로, 이미지 확장자, 이미지 format확인
( images_paths : n, kernel_size : 1, output_path : 1 )
*/
/* 확장자확인
 * open, read part
 * 중복여부 확인
 * 파일 내용 class 안에 담기
 */
bool ImageProcessor::processFile(int argc, char **argv) {
    if (argc != 2) {
        throw std::invalid_argument("Usage: ./ImageProcessor <image_file>");
    }
    std::string configfilePath = argv[1];
    checkFileExtension(configfilePath, ".txt");
    checkIfRegularFile(configfilePath);
    openAndReadFile(configfilePath);

    return true;
}

// 파일 확장자확인.
void ImageProcessor::checkFileExtension(const std::string &filePath, const std::string &extension) {
    if (filePath.substr(filePath.size() - 4, 4) != extension) {
        throw std::invalid_argument("Image file must be a " + extension + " image");
    }
}

// 파일 존재여부 확인
void ImageProcessor::checkIfRegularFile(const std::string &filePath) {
    if (!std::filesystem::exists(filePath) || !std::filesystem::is_regular_file(filePath)) {
        throw std::invalid_argument("Image file must be a regular file");
    }
}

// 경로 존재여부 확인
void ImageProcessor::checkIfRegularRoot(const std::string &path) {
    if(!std::filesystem::exists(path)) {
        throw std::invalid_argument("Image file must be a regular Root");
    }
}

// 파일 정보 담기
void ImageProcessor::openAndReadFile(const std::string &configfilePath) {
    std::fstream configfile(configfilePath);
    if (!configfile.is_open()) {
        throw std::invalid_argument("Failed to open config file");
    }

    std::string line;
    std::vector<std::string> imagePaths;
    int kernelSize;
    int kernelSizeCount = 0;
    std::string outputPath;
    int outputPathCount = 0;
    while (std::getline(configfile, line)) {
        size_t pos = line.find('=');
        if (pos == std::string::npos) {
            throw std::invalid_argument("Failed to parse config file (=)");
        }
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        value.erase(remove(value.begin(), value.end(), '\"'), value.end());
        if (key == "image_paths") {
            // checkIfRegularFile(value); // 일단 보류 (어디서해야할지 고민)
            imagePaths.push_back(value);
        }
        else if (key == "kernel_size") {
            kernelSize = std::stoi(value);
            kernelSizeCount++;
        }
        else if (key == "output_path") {
            // checkIfRegularRoot(value); // 일단 보류 (어디서해야할지 고민)
            outputPath = value;
            outputPathCount++;
        }
        else {
            throw std::invalid_argument("Failed to parse config file (key)");
        }
    }

    if (imagePaths.empty()) {
        throw std::invalid_argument("Failed to parse config file (1 < imagePaths)");
    }
    if (1 < outputPathCount) {
        throw std::invalid_argument("Failed to parse config file (outputPath == 1)");
    }
    if (1 < kernelSizeCount) {
        throw std::invalid_argument("Failed to parse config file (kernelSize == 1)");
    }
    setImagePaths(imagePaths);
    setKernelSize(kernelSize);
    setOutputPath(outputPath);
}

void ImageProcessor::setImagePaths(const std::vector<std::string>& paths) {
    _imagePaths = paths;
}
std::vector<std::string> ImageProcessor::getImagePaths() {
    return _imagePaths;
}

int ImageProcessor::getImagePathsSize() {
    return _imagePaths.size();
}

const std::string ImageProcessor::getImagePathNumber(int n) {
    return _imagePaths[n];
}

void ImageProcessor::setOutputPath(const std::string& path) {
    _outputPath = path;
}

std::string ImageProcessor::getOutputPath() {
    return _outputPath;
}

void ImageProcessor::setKernelSize(int kernelSize) {
    _kernelSize = kernelSize;
}

int ImageProcessor::getKernelSize() {
    return _kernelSize;
}