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
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}