#ifndef IMAGE_PROCESSOR_HPP_
#define IMAGE_PROCESSOR_HPP_

#ifdef _WIN32
    #ifdef IMAGE_PROCESSOR_EXPORTS
        #define IMAGE_PROCESSOR_API __declspec(dllexport)
    #else
        #define IMAGE_PROCESSOR_API __declspec(dllimport)
    #endif
#else
    #define IMAGE_PROCESSOR_API __attribute__((visibility("default")))  // Mac/Linux에서 사용할 export
#endif

#include <iostream>
#include <fstream>

#include "ImageObject.hpp"

class IMAGE_PROCESSOR_API ImageProcessor
{
public:
    ImageProcessor() {};
    ~ImageProcessor() {};

    bool processFile(int argc, char* argv[]);
    bool validateImage(const ImageObject* src, ImageObject* dst);
    virtual bool ImageBlur(const ImageObject* src, ImageObject* dst, const int kernelSize) = 0;

    void setImagePaths(const std::vector<std::string>& paths);
    std::vector<std::string> getImagePaths();
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
    bool checkImageParameters(int argc, char **argv);
};

#endif // IMAGE_PROCESSOR_HPP_