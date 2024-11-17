pipeline {
    agent any
    stages {
        stage('Docker Build') {
            steps {
                sh '''
                cd build_pipeline
                docker build -f dockerfile.build -t blood-pressure-tracker-build .
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
