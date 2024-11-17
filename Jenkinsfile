pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                // Navigate to the src directory and run build.sh
                sh '''
                cd src
                chmod +x build.sh
                ./build.sh
                '''
            }
        }

        stage('Test') {
            steps {
                echo 'Running tests...'
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying application...'
                echo 'hello!'
            }
        }
    }
}
