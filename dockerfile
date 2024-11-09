FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y \
    gcc \
    g++ \
    make \
    build-essential \
    libmysqlcppconn-dev && \
    apt-get clean


# Creating the work dir, for the files. 
WORKDIR /usr/src/source
COPY /src/ /usr/src/source/

RUN chmod += build.sh

ENTRYPOINT [ "/usr/src/source/build.sh" ]




