#!/usr/bin/env bash

# Exit on error
set -e

# Create build directory
mkdir -p build
cd build

# Run CMake
cmake ..

# Build
make

# Run the program
./nanotekspice

# Run the tests
# make tests_run
