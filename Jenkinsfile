pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building the project...'
                cd src
                ./build_old.sh
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
