pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh '''
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

                chmod +x src/build.sh
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
