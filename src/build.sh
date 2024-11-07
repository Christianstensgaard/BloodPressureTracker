#!/bin/bash

echo "Checking if the container is already running..."

# Check if the container is running
if docker ps -q -f name=db_service > /dev/null; then
    echo "Container is running, stopping and removing it..."
    docker stop db_service
    docker rm db_service
else
    echo "No running container found."
fi

echo "Building the application locally..."

# Build the application locally using cmake
mkdir -p build
cd build
cmake ..
cmake --build . -j

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Application build failed! Exiting..."
    exit 1
fi
cd ..

echo "Building the Docker image..."

# Build the Docker image, copying the already built binary
docker build -t database .

# Check if the Docker build was successful
if [ $? -ne 0 ]; then
    echo "Docker build failed! Exiting..."
    exit 1
fi

echo "Running the Docker container..."

# Run the Docker container
docker run --name db_service database

# Check if the container started successfully-.æ
if [ $? -ne 0 ]; then
    echo "Failed to start the container! Exiting..."
    exit 1
fi

echo "Docker container started successfully."