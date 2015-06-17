#Makefile para construir towdef-ai

CC = g++
OBJS = main.o Game.o Board.o Entity.o EntityManager.o UI.o GraphicalUI.o Util.o Genetic.o TextUI.o
ARGS = -O3
CFLAGS = -Wall -std=c++11 -c $(ARGS)
LFLAGS = -Wall -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

all: $(OBJS)
	$(CC) $(OBJS) -o towdef.out $(LFLAGS) 

main.o: main.cpp Game.hpp GraphicalUI.hpp Util.hpp
	$(CC) $(CFLAGS) main.cpp

Game.o: Game.hpp Game.cpp Board.hpp Entity.hpp UI.hpp EntityManager.hpp
	$(CC) $(CFLAGS) Game.cpp

Board.o: Board.hpp Board.cpp defines.hpp Entity.hpp
	$(CC) $(CFLAGS) Board.cpp

Entity.o: Entity.hpp Entity.cpp defines.hpp
	$(CC) $(CFLAGS) Entity.cpp 

EntityManager.o: EntityManager.hpp EntityManager.cpp Entity.hpp
	$(CC) $(CFLAGS) EntityManager.cpp 

UI.o: UI.hpp UI.cpp
	$(CC) $(CFLAGS) UI.cpp 

GraphicalUI.o: GraphicalUI.hpp GraphicalUI.cpp defines.hpp UI.hpp
	$(CC) $(CFLAGS) GraphicalUI.cpp 

Util.o: Util.hpp Util.cpp
	$(CC) $(CFLAGS) Util.cpp

Genetic.o: Genetic.hpp defines.hpp Game.hpp Genetic.cpp
	$(CC) $(CFLAGS) Genetic.cpp

TextUI.o: TextUI.hpp TextUI.cpp defines.hpp
	$(CC) $(CFLAGS) TextUI.cpp

clean:
	\rm *.o towdef.out
