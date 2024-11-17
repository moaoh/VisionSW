#include "Processor.hpp"
#include "OpencvDll.hpp"
#include "CustomDll.hpp"
#include "Logger.hpp"

void compareAndLog(const std::string& imagePath, const cv::Mat& mat1, const cv::Mat& mat2) {
  if (mat1.size() != mat2.size() || mat1.type() != mat2.type() || cv::countNonZero(mat1 != mat2) != 0) {
    Logger::instance().info(imagePath + " are different");
  }
  else {
    Logger::instance().info(imagePath + " are identical");
  }
}

int main(int argc, const char * argv[]) {
  OpencvDll opencv("opencv");
  CustomDll custom("custom");

  try {
    GetConfigProcessor config(argc, argv);
    Processor opencvProcessor(opencv);
    Processor customProcessor(custom);

    for (int i = 0; i < config.getImagePathsSize(); i++) {
      std::string outputPath = config.getOutputPath();
      int kernelSize = config.getKernelSize();
      std::string imagePath = config.getImagePaths()[i];

      cv::Mat customMat = customProcessor.run(imagePath, outputPath, kernelSize);
      cv::Mat opencvMat = opencvProcessor.run(imagePath, outputPath, kernelSize);
      if (!opencvMat.empty() && !customMat.empty()) {
        compareAndLog(imagePath, opencvMat, customMat);
      }
    }
  }
  catch(const std::exception& e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
  }

  return 0;
}