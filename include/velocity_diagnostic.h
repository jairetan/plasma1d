//Record kinetic energy at each time of the simulation
#pragma once

#include <fstream>
#include <vector>
#include <particle.h>
#include "parameters.h"
#include "to_string.h"
void velocity_diagnostic (std::vector <Particle *> *, int iter);
