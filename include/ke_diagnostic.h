//Record kinetic energy at each time of the simulation
#include <fstream>
#include <vector>
#include <particle.h>
#pragma once

void ke_diagnostic (std::vector <Particle *> *, double);
void pe_diagnostic (std::vector <double> *, std::vector <double> *, double);
