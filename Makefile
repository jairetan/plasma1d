CC=g++
CFLAGS= -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all -std=c++11
DEPS=particle.h
SRC=./src/
INC=./include/
OBJECTS=./object/
FILES:=$(wildcard $(SRC)*.cpp)
OBJ:=$(FILES:$(SRC)%.cpp=%.o)

all: run

%.o: $(SRC)%.cpp $(INC)%.h
	$(CC) $(CFLAGS) -I./$(INC) -c $<

run: $(OBJ) -lfftw3 -lm -lgsl -lgslcblas
	$(CC) -o $@ $^
	@mv *.o $(OBJECTS)

clean:
	@rm -f $(OBJECTS)*.o run ./data/*.dat *.dat *.o
