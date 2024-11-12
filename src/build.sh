#!/bin/bash

echo "Building the application locally..."

# Clean out the build directory to ensure a fresh build
rm -rf ../build_output/*
mkdir -p ../build_output
cd ../build_output

# Run CMake configuration and build commands
cmake ../src/  # Point this to the src directory
cmake --build . -j

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Application build failed! Exiting..."
    exit 1
fi

echo "Build completed successfully."


# Check if container 'bms_db' is running
if [ "$(docker ps -q -f name=bms_db)" ]; then
    echo "bms_db container is already running."
else
    echo "Starting bms_db container..."
    docker run --name bms_db -d -p 3306:3306 bms_db
fi

./BloodPressureTracker

