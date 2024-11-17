pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh '''
                ls
                docker build -t service_build -f build_pipeline/dockerfile.build .
                docker create --name temp-builder my-app-builder
                docker cp temp-builder:/app/build ./build
                docker rm temp-builder
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
