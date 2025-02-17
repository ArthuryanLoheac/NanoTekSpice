#!/usr/bin/env bash

# Exit on error
set -e

# Check for arguments
if [ "$1" == "-f" ]; then
    rm -rf build
    exit 0
elif [ "$1" == "-r" ]; then
    rm -rf build
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

if [ "$1" == "-t" ]; then
    make tests_run
else
    ./nanotekspice ../tests/Exemple/nts_single/xor.nts
fi
