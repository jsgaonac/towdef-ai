#Makefile para construir towdef-ai

CC = g++
OBJS = main.o Game.o Board.o GameEntity.o
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

towdef.out : $(OBJS)
	$(CC) $(OBJS) -o towdef.out $(LFLAGS) 

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Game.o : Game.h Game.cpp
	$(CC) $(CFLAGS) Game.cpp

Board.o : Board.h Board.cpp
	$(CC) $(CFLAGS) Board.cpp

GameEntity.o : GameEntity.h GameEntity.cpp
	$(CC) $(CFLAGS) GameEntity.cpp 

clean:
	\rm *.o towdef.out
