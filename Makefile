CC=g++
CFLAGS= -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all -std=c++11
SRC=./src/
INC=./include/
UNIT=./unit_test/
OBJECTS=./object/
FILES:=$(wildcard $(SRC)*.cpp)
OBJ:=$(FILES:$(SRC)%.cpp=%.o)

all: run

%.o: $(SRC)%.cpp $(INC)%.h
	$(CC) $(CFLAGS) -I./$(INC) -c $<

%.o: $(UNIT)%.cpp $(INC)%.h
	$(CC) $(CFLAGS) -I./$(INC) -c $<

run: $(OBJ) -lfftw3 -lm -lgsl -lgslcblas
	$(CC) -o $@ $^
	@mv *.o $(OBJECTS)

clean:
	@rm -f $(OBJECTS)*.o run ./data/*.dat *.dat *.o
