FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y \
    gcc \
    g++ \
    make \
    build-essential \
    libmysqlcppconn-dev && \
    apt-get clean

RUN apt-get 



RUN ls