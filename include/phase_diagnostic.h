//Record positions of particles at each time
#pragma once
#include <fstream>
#include <vector>
#include <particle.h>
#include "parameters.h"
#include <string>
#include "to_string.h"

void phase_diagnostic (std::vector <Particle *> *, int i);
