CC=g++
CFLAGS= -Wall -g -O0 -Wwrite-strings -Wshadow -pedantic-errors -fstack-protector-all
DEPS=particle.h
OBJ=adjacent-coods.o density.o electron.o altfield.o init-pos.o move.o particle.o proton.o run-man.o weighing.o jmod.o ke_diagnostic.o mom_diagnostic.o pos_diagnostic.o diagnostics.o field_diagnostic.o pot_diagnostic.o init_v.o density_diagnostic.o zero_order_weighing.o velocity_diagnostic.o psd.o
SRC=./src/
INC=./include/
OBJECTS=./object/

all: run

%.o: $(SRC)%.cpp $(INC)%.h
	$(CC) $(CFLAGS) -I./$(INC) -c $<

run: $(OBJ) -lfftw3 -lm -lgsl -lgslcblas
	$(CC) -o $@ $^
	mv *.o $(OBJECTS)

clean:
	@rm -f $(OBJECTS)*.o run ./data/*.dat
