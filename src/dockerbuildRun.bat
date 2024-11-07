@echo off
cls
echo Checking if the container is already running...
docker ps -q -f name=db_service >nul
if %errorlevel% equ 0 (
    echo Container is running, stopping and removing it...
    docker stop db_service
    docker rm db_service
) else (
    echo No running container found.
)

echo Building the Docker image...
docker build -t database .

if %errorlevel% neq 0 (
    echo Build failed! Exiting...
    exit /b %errorlevel%
)

echo Running the Docker container...
docker run --name db_service database

if %errorlevel% neq 0 (
    echo Failed to start the container! Exiting...
    exit /b %errorlevel%
)

pause