#!/usr/bin/env bash

# Exit on error
set -e

# Check for arguments
if [ "$1" == "-f" ]; then
    rm -rf build
    rm -f nanotekspice
    rm -f unit_tests
    exit 0
elif [ "$1" == "-r" ]; then
    rm -rf build
    rm -f nanotekspice
    rm -f unit_tests
    ./build.sh
    exit 0
fi

# Create build directory
mkdir -p build
cd build

# Run CMake
cmake ..

# Build
make -j$(nproc)

# Copy binary to root
cp ./nanotekspice ../nanotekspice
cp ./unit_tests ../unit_tests
cd ..

if [ "$1" == "-t" ]; then
    ./unit_tests
    gcovr --exclude include/ --exclude tests/ --exclude CMakeFiles/
else
    ./nanotekspice $1
fi
