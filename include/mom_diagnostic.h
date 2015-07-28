//Record system momentum at each time

#pragma once
#include <fstream>
#include <vector>
#include <particle.h>
#include "out_writer.h"
void mom_diagnostic (std::vector <Particle *> *, double);
