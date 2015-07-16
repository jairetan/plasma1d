CC=g++
CFLAGS= -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all
DEPS=particle.h
OBJ=density.o adjacent-coods.o electron.o altfield.o move.o particle.o proton.o weighing.o jmod.o unit_run.o
INC=/home/jtan/my-plasma/1dcpp/include/

all: run

%.o: %.cpp $(INC)%.h
	$(CC) $(CFLAGS) -I$(INC) -c $<

run: $(OBJ) -lfftw3 -lm -lgsl -lgslcblas
	$(CC) -o $@ $^

clean:
	@rm -f *.o run *.dat
