pipeline {
    agent any
    stages {
        stage('Build_test') {
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
                    chmod +x src/build_test.sh
                    
                    # Run the build script
                    ./src/build_test.sh
                  '''
            }
          }
        stage('Run Test Script') {
            steps {
                sh '''
                cd build_test
                ./BloodPressureTracker
                '''
                
            }
        }

        stage('Build production') {
            steps {
                sh '''
                ./src/build.sh
                '''
              archiveArtifacts artifacts: 'build/*', allowEmptyArchive: true
            }
        }
    }
}
