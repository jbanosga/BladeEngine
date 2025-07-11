#!/bin/bash

docker build . -t game-project:latest
docker run game-project:latest