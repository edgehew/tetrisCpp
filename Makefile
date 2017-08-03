# Makefile

tetris: tetris.o
	g++ tetris.o -o tetris -lsfml-graphics -lsfml-window -lsfml-system

tetris.o: tetris.cpp
	g++ -c tetris.cpp

clean:
	rm tetris tetris.o
