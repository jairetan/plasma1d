//Change position fo particles

#pragma once
#include <vector>
#include <cmath>
#include "particle.h"
#include "weighing.h"
#include "adjacent_coods.h"

#include "parameters.h"

void move_particles (std::vector <Particle> * particles, std::vector <double> *field);
