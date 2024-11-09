#!/bin/bash

CONTAINER_NAME="system_application"

echo "Checking if the container $CONTAINER_NAME already exists..."

# Check if the container exists (either running or stopped)
if docker ps -a -q -f name=$CONTAINER_NAME > /dev/null; then
    echo "Container $CONTAINER_NAME exists, stopping and removing it..."
    docker stop $CONTAINER_NAME 2>/dev/null
    docker rm $CONTAINER_NAME
else
    echo "No existing container with the name $CONTAINER_NAME found."
fi

echo "Building the application locally..."

# Build the application locally using CMake
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

# Run the Docker container using Docker Compose
docker-compose up --build

# Check if the container started successfully
if [ $? -ne 0 ]; then
    echo "Failed to start the container! Exiting..."
    exit 1
fi

echo "Docker container started successfully."
