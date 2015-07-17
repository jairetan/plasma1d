//Record kinetic energy at each time of the simulation
#include <fstream>
#include <vector>
#include <particle.h>
#pragma once

double ke_diagnostic (std::vector <Particle *> *, double);
double pe_diagnostic (std::vector <double> *, std::vector <double> *, double);
void energy_diagnostic (std::vector <Particle *> *, std::vector <double> *, std::vector <double> *, double);
