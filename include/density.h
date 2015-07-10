//Calculate charge density
#include "particle.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "adjacent-coods.h"
#include "weighing.h"

#pragma once

void calc_density (std::vector <double> *density, std::vector <Particle *> *particles);
