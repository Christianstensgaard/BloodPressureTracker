pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh '''
                    # Update package list and install necessary dependencies
                    apt-get update && \
                    apt-get install -y \
                    build-essential \
                    cmake \
                    g++ \
                    libmysqlcppconn-dev \
                    libpthread-stubs0-dev \
                    libboost-all-dev \
                    libstdc++6 \
                    clang \
                    && rm -rf /var/lib/apt/lists/*

                    # Make sure the build.sh script is executable
                    chmod +x src/build.sh
                    
                    # Run the build script
                    ./src/build.sh
                  '''
            }
          }
        stage('Run Build Script') {
            steps {
                sh '''
                docker run --rm blood-pressure-tracker-build bash -c "
                cd /app && chmod +x build.sh && ./build.sh
                "
                '''
            }
        }
    }
}
