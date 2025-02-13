#!/usr/bin/env bash

# Exit on error
set -e

# Remove build directory
rm -rf build

# Create build directory
mkdir -p build
cd build

# Run CMake
cmake ..

# Build
make

# Check for arguments
if [ "$1" == "-t" ]; then
    # Run the tests
    make tests_run
else
    # Run the program
    ./nanotekspice
fi
