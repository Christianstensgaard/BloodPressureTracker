# Use an official Ubuntu image
FROM ubuntu:latest

# Install necessary tools for running the application
RUN apt-get update && \
    apt-get install -y \
    libmysqlcppconn-dev \
    && rm -rf /var/lib/apt/lists/*

# Create a directory for the application
WORKDIR /usr/src/app

# Copy only the built application (from the local machine)
COPY /build_output/BloodPressureTracker /usr/src/app/

# Set library path for runtime linking (MySQL Connector/C++)
ENV LD_LIBRARY_PATH="/usr/local/lib/mysqlcppconn:$LD_LIBRARY_PATH"

# Define the default command to run your app
CMD ["./BloodPressureTracker"]