#Makefile para construir towdef-ai

CC = g++
OBJS = main.o Game.o Board.o
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

towdef.out : $(OBJS)
	$(CC) $(OBJS) -o BadBrothers $(LFLAGS) 

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Game.o : Game.h Entity.h Map.h Game.cpp
	$(CC) $(CFLAGS) Game.cpp

Board.o : Board.h Board.cpp
	$(CC) $(CFLAGS) Board.cpp

clean:
	\rm *.o towdef.out
