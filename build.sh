#! /bin/bash

echo "Building PingPong..."
g++ src/main.cpp src/Game.cpp src/Ball.cpp src/Player.cpp -o main -lSDL2
