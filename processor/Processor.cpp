#include "Processor.hpp"

// 흑백여부 판별
bool Processor::validateImage(const cv::Mat* src) {
  if (src->empty() || src->channels() != 1) {
    std::cout << "image.channels() : " << src->channels() << std::endl;
    return false;
  }
  return true;
}

Processor::Processor(GetConfigProcessor& config, ImageProcessor& imageProcessor) {
  const int imagePathSize = config.getImagePathsSize();
  ImageObject dst(cv::imread(config.getOutputPath()));
  dst.setOutputPath(config.getOutputPath());
  int kernelSize = config.getKernelSize();

  for (int i = 0; i < imagePathSize; i++) {
    cv::Mat srcMat = cv::imread(config.getImagePaths()[i], cv::IMREAD_UNCHANGED);

    if (validateImage(&srcMat)) {
      cv::cvtColor(srcMat, srcMat, cv::COLOR_BGRA2BGR);
      ImageObject src(srcMat);
      std::filesystem::path p(config.getImagePaths()[i]);
      std::string filename = p.filename().string();
      src.setImageName(filename);
      imageProcessor.ImageBlur(&src, &dst, kernelSize);
    }
    else {
      std::cout << config.getImagePaths()[i] << std::endl;
    }
  }
}
