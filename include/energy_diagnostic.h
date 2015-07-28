//Record kinetic energy at each time of the simulation
#pragma once
#include <fstream>
#include <vector>
#include <particle.h>
#include "out_writer.h"

double ke_diagnostic (std::vector <Particle *> *, double);
double pe_diagnostic (std::vector <double> *, std::vector <double> *, double);
void energy_diagnostic (std::vector <Particle *> *, std::vector <double> *, std::vector <double> *, double);
