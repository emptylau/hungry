OBJ=test
CC=g++
FLAG=-std=c++11

OBJ: main.o dataqueue.hpp
	$(CC) -o $(OBJ) $(FLAG) main.o dataqueue.hpp

main.o: main.cpp
	$(CC) -o main.o $(FLAG) -c main.cpp

.PHONY: clean purge
clean:
	rm -rf *.o *.gch

purge:
	rm -rf *.o *.gch $(OBJ)
