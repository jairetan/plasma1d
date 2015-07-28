//Determine which points are adjacent to particle position
#pragma once

#include <vector>
#include "particle.h"
#include "jmod.h"
#include "wrap_around.h"

void adjacent_points (Particle *particle, int *points);
