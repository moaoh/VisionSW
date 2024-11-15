#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>

#include "Processor.hpp"
#include "OpencvDll.hpp"
#include "CustomDll.hpp"

int main(int argc, const char * argv[]) {
    OpencvDll opencv("opencv_");
    CustomDll custom("custom_");

    GetConfigProcessor config(argc, argv);
    Processor(config, opencv);
    Processor(config, custom);
    return 0;
}