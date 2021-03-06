//Record kinetic energy at each time of the simulation
#pragma once

#include <vector>
#include <particle.h>
#include "out_writer.h"
#include "transform_wrapper.h"

double ke_diagnostic (std::vector <Particle> *, double);
double pe_diagnostic (std::vector <double> *potential, std::vector <double> *density, double t);
void energy_diagnostic (std::vector <Particle> *, std::vector <double> *, std::vector <double> *, double);
