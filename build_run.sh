#!/bin/bash

docker build . -t game-project:latest
docker run --rm game-project:latest