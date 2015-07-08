//Change position fo particles

#include <vector>
#include <cmath>
#include "particle.h"
#include "weighing.h"
#include "adjacent-coods.h"
#pragma once

void move_particles (std::vector <Particle *> * particles, std::vector <double> *field, double dt, int divisions);
