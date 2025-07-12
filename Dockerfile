FROM ubuntu:22.04 AS build

RUN apt update && apt install -y \
    build-essential \
    cmake \
    git

WORKDIR /project

RUN mkdir deps && cd deps \
    git clone https://github.com/libsdl-org/SDL.git -b SDL2 && \
    cd SDL2 && \
    ./configure && make all && make install

#COPY ./deps /project/deps
COPY CMakeLists.txt /project/CMakeLists.txt
COPY ./include /project/include
COPY ./src /project/src

RUN mkdir build && cd build && \
    cmake .. && \
    cmake --build .