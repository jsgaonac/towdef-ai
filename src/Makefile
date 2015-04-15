#Makefile para construir towdef-ai

CC = g++
OBJS = main.o Game.o Board.o Entity.o
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

towdef.out : $(OBJS)
	$(CC) $(OBJS) -o towdef.out $(LFLAGS) 

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Game.o : Game.hpp Game.cpp
	$(CC) $(CFLAGS) Game.cpp

Board.o : Board.hpp Board.cpp
	$(CC) $(CFLAGS) Board.cpp

Entity.o : Entity.hpp Entity.cpp
	$(CC) $(CFLAGS) Entity.cpp 

clean:
	\rm *.o towdef.out
