//Calculate charge density
#pragma once

#include "particle.h"
#include <vector>

#include <cmath>
#include "adjacent_coods.h"
#include "weighing.h"

void calc_density (std::vector <Particle *> *particles,std::vector <double> *density);
