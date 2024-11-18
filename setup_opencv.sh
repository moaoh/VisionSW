#!/bin/bash

set -e

REPO_URL="https://github.com/opencv/opencv.git"
TARGET_DIR="opencv"
VERSION="4.x"

if [ -d "$TARGET_DIR" ]; then
    echo "Directory '$TARGET_DIR' already exists. Skipping clone."
else
    echo "clone '$TARGET_DIR'"
    git clone $REPO_URL
    cd $TARGET_DIR
    git checkout $VERSION
fi

mkdir -p build
cd build
cmake ..
make -j4

echo "OpenCV setup completed. Ready to build!"