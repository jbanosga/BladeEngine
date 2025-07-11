FROM ubuntu:22.04 AS build


# RUN sudo apt update && apt install -y build-essential git make \
# pkg-config cmake ninja-build gnome-desktop-testing libasound2-dev libpulse-dev \
# libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
# libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev \
# libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
# libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev

RUN apt update && apt install -y \
    build-essential \
    cmake \
    && apt clean

WORKDIR /project

COPY ./src /project/src
COPY ./include /project/include
COPY CMakeLists.txt /project/CMakeLists.txt

RUN mkdir build && cd build && \
    cmake .. && \
    cmake --build .

FROM scratch

COPY --from=build /project/build/SplitCrit /SplitCrit

CMD [ "/SplitCrit" ]