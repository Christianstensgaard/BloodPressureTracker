#!/bin/bash

echo "Building the application locally..."

rm -rf ../build_output/*
mkdir -p ../build_output
cd ../build_output

cmake ../src/ 
cmake --build . -j

if [ $? -ne 0 ]; then
    echo "Application build failed! Exiting..."
    exit 1
fi

echo "Build completed successfully."


if [ "$(docker ps -q -f name=bms_db)" ]; then
    echo "bms_db container is already running."
else
    echo "Starting bms_db container..."
    docker run --name bms_db -d -p 3306:3306 bms_db
fi

./BloodPressureTracker

