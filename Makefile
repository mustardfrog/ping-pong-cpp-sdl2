CC=g++
SRCS=src/main.cpp src/Game.cpp src/Ball.cpp src/Player.cpp
FLAGS=-lSDL2 

main: $(SRCS)
	$(CC) $(SRCS) -o main $(FLAGS)
