#include <iostream>
#include <fstream>

// #include <nlohmann/json.hpp>
#include <opencv2/opencv.hpp>

#include "OpencvDll.hpp"
#include "CustomDll.hpp"

int main(int argc, char *argv[]) {
    try {
        OpencvDll opencvDllObject;
        opencvDllObject.processFile(argc, argv);
        int size = opencvDllObject.getImagePathsSize();

        int kernelSize = opencvDllObject.getKernelSize(); // ksize
        std::string dstPath = opencvDllObject.getOutputPath(); // dst
        cv::Mat output = cv::imread(dstPath);
        ImageObject dst(output);

        for (int i = 0; i < size; i++) {
            std::string imagePath = opencvDllObject.getImagePathNumber(i);
            cv::Mat image = cv::imread(imagePath);
            ImageObject src(image);
            if (opencvDllObject.validateImage(&src)) {
                opencvDllObject.ImageBlur(&src, &dst, kernelSize);
            }
        }
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}