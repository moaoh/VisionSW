#include "Processor.hpp"

// 흑백여부 판별
bool Processor::validateImage(const cv::Mat* src) {
  if (src->empty() || src->channels() != 1) {
    return false;
  }
  return true;
}

Processor::Processor(GetConfigProcessor& config, ImageProcessor& imageProcessor) {
  const int imagePathSize = config.getImagePathsSize();
  ImageObject dst(cv::imread(config.getOutputPath()));
  dst.setOutputPath(config.getOutputPath());
  int kernelSize = config.getKernelSize(); // TODO: 홀수 필터링 지정필요

  for (int i = 0; i < imagePathSize; i++) {
    cv::Mat srcMat = cv::imread(config.getImagePaths()[i], cv::IMREAD_UNCHANGED);
    if (validateImage(&srcMat)) {
      ImageObject src(srcMat);
      std::filesystem::path p(config.getImagePaths()[i]);
      std::string filename = p.filename().string();
      src.setImageName(filename);
      imageProcessor.ImageBlur(&src, &dst, kernelSize);
    }
    else {
      std::cout << "Failed Image Load (" << config.getImagePaths()[i] << ")" << std::endl;
    }
  }
}
