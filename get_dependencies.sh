#!/bin/bash

git clone https://github.com/libsdl-org/SDL.git -b SDL2
./SDL/configure 
make all && make install