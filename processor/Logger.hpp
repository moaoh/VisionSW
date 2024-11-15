#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Logger
{
public:
  static Logger& instance();
  void info(const std::string& message);
  void warn(const std::string& message);
  void error(const std::string& message);

private:
  std::string _logPath;
  std::ofstream logFile;

  Logger() = delete;
  Logger(const Logger& logger) = delete;
  Logger& operator=(const Logger& logger) = delete;
  Logger(const std::string& filename);
  ~Logger();

  void log(const std::string& logLevel, const std::string& message);
};