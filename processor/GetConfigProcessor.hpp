#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class GetConfigProcessor
{
public:
    GetConfigProcessor(int argc, const char* argv[]);
    ~GetConfigProcessor() {};

    void setImagePaths(const std::vector<std::string>& paths);
    std::vector<std::string> getImagePaths();
    int getImagePathsSize();
    void setOutputPath(const std::string& path);
    std::string getOutputPath();
    void setKernelSize(int kernelSize);
    int getKernelSize();

private:
    std::vector<std::string> _imagePaths;
    std::string _outputPath;
    int _kernelSize;

    void checkFileExtension(const std::string &configFile, const std::string &extension);
    void openAndReadFile(const std::string &configfile);
    void checkIfRegularFile(const std::string &filePath);
    void checkIfValidPath(const std::string &path);
};