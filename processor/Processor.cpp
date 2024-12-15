#include "Processor.hpp"

Processor::Processor(ImageProcessor& imageProcessor)
  : _imageProcessor(imageProcessor) {}

// 흑백여부 판별
bool Processor::isBlackAndWhite(const cv::Mat* src) {
  if (src->empty() || src->channels() != 1) {
    return false;
  }
  return true;
}

/*
* TODO : Before보다 After가 메모리 측정값이 더 적은 경우가 존재.
*  그로인해 음수가 나와 오버플로우 발생 해결 필요.
 */
// 메모리 사용량
size_t Processor::getMemoryUsage() {
  size_t memoryUsage = 0;
#if defined(_WIN32) || defined(_WIN64)
  PROCESS_MEMORY_COUNTERS pmc;
  if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
    memoryUsage = pmc.WorkingSetSize / 1024; // KB
  }
#elif defined(__APPLE__) || defined(__MACH__)
  task_basic_info_data_t info;
  mach_msg_type_number_t infoCount = TASK_BASIC_INFO_COUNT;
  if (task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&info, &infoCount) == KERN_SUCCESS) {
    memoryUsage = info.resident_size / 1024; // KB
  } else {
    memoryUsage = 0;
  }
#endif

//  size_t memoryUsageMB = memoryUsage / 1024;  // KB -> MB

  return memoryUsage; // KB
//  return memoryUsageMB;
}

// memory사용량 및 시간출력
void Processor::logMemoryAndTime(const std::string& prefix,
  size_t memoryBefore, size_t memoryAfter,
  const std::chrono::high_resolution_clock::time_point& start,
  const std::chrono::high_resolution_clock::time_point& end) {
  std::chrono::duration<double> duration = end - start;
  size_t memoryDifference = (memoryAfter > memoryBefore) ? (memoryAfter - memoryBefore) : 0;

  if (memoryDifference == 0) {
    Logger::instance().info("[" + prefix + "]" + " error : Memory measurement error");
  }
  else {
    Logger::instance().info("[" + prefix + "] Memory Usage :" + std::to_string(memoryDifference) + "KB");
  }
  Logger::instance().info("[" + prefix + "] duration time :" + std::to_string(duration.count()));
}

cv::Mat Processor::run(const std::string& imagePath, const std::string& outputPath, int kernelSize) {
  const std::string& prefix = _imageProcessor.getPrefix();

  cv::Mat srcMat = cv::imread(imagePath, cv::IMREAD_UNCHANGED);
  cv::Mat dstMat;
  if (isBlackAndWhite(&srcMat)) {
    std::filesystem::path p(imagePath);
    std::string filename = p.filename().string();

    size_t memoryBefore = getMemoryUsage();
    auto start = std::chrono::high_resolution_clock::now();

    ImageObject dst(dstMat);
    ImageObject src(srcMat);

    if (_imageProcessor.ImageBlur(&src, &dst, kernelSize)) {
      dstMat = dst.toMat();
      if (cv::imwrite((outputPath + prefix + filename), dstMat)) {
        Logger::instance().info("[" + prefix + "] Image saved to " + outputPath + prefix + filename);
      }
      else {
        Logger::instance().error("Failed to save image to " + outputPath + prefix + filename);
      }
    }
    else {
      Logger::instance().error("Failed to save image to " + outputPath + prefix + filename);
    }
    size_t memoryAfter = getMemoryUsage();
    auto end = std::chrono::high_resolution_clock::now();
    logMemoryAndTime(prefix, memoryBefore, memoryAfter, start, end);
  }
  else {
    Logger::instance().warn("It's not a black-and-white image " + imagePath);
  }

  return dstMat;
}