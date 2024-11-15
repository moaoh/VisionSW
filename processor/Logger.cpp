#include "Logger.hpp"

Logger& Logger::instance() {
  static Logger instance("image_blur.log");
  return instance;
}

Logger::Logger(const std::string& filename) {
  logFile.open(filename, std::ios_base::app);
  if (!logFile.is_open()) {
    std::cerr << "Failed to open log file" << std::endl;
  }
}

Logger::~Logger() {
  if (logFile.is_open()) {
    logFile.close();
  }
}

void Logger::info(const std::string& message) {
  log("INFO", message);
}

void Logger::warn(const std::string& message) {
  log("WARNING", message);
}

void Logger::error(const std::string& message) {
  log("ERROR", message);
}

void Logger::log(const std::string& logLevel, const std::string& message) {

  if (logFile.is_open()) {
    std::time_t now = std::time(0);
    char* dt = std::ctime(&now);
    dt[strlen(dt) - 1] = '\0';
    logFile << "[" << dt << "] [" << logLevel << "] " << message << std::endl;
    logFile.flush();
  }
}