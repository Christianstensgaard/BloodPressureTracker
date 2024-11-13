# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(BloodPressureTracker VERSION 1.0)

# Set C++ standard to C++11 (or whichever version you prefer)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/src/headers)

# Specify the source files for the project
set(SRC_FILES
    bloodMeasurement.cpp
    databaseController.cpp
    patientController.cpp
    measurementController.cpp
    tcpSocket.cpp
    main.cpp
)

# Add executable target
add_executable(${PROJECT_NAME} ${SRC_FILES})


# Link MySQL Connector/C++ library
find_library(MYSQLCPP_LIB mysqlcppconn PATHS /usr/lib /usr/local/lib)
if (MYSQLCPP_LIB)
    target_link_libraries(${PROJECT_NAME} ${MYSQLCPP_LIB})
else()
    message(FATAL_ERROR "MySQL Connector/C++ library not found")
endif()

# # Docker-related commands - use external commands within CMake
# add_custom_target(
#     docker
#     COMMAND docker build -t database -f dockerfile .
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "Building the Docker image"
# )

# add_custom_target(
#     run
#     COMMAND docker run --name db_service database
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "Running the Docker container"
# )

# add_custom_target(
#     clean_docker
#     COMMAND docker ps -q -f name=db_service | grep -q . && docker stop db_service && docker rm db_service || echo "No running container found."
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#     COMMENT "Stopping and removing the Docker container if it exists"
# )

# # Combine Docker tasks into one target
# add_custom_target(
#     full_build
#     DEPENDS clean_docker docker run
#     COMMENT "Full Build: Clean Docker, Build Image, Run Container"
# )
