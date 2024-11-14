#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>

#include "Processor.hpp"
#include "OpencvDll.hpp"
#include "GetConfigProcessor.hpp"
// #include "CustomDll.hpp"

int main(int argc, const char * argv[]) {
    OpencvDll opencv;
    // CustomDll custom;

    GetConfigProcessor config(argc, argv);
    Processor(config, opencv);
    // Processor(config, custom);
    return 0;
}