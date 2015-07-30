//Load diagnostic functions
#include "energy_diagnostic.h"
#include "pos_diagnostic.h"
#include "mom_diagnostic.h"
#include "mode_diagnostic.h"

#pragma once

void time_history_diagnostics (std::vector <Particle*> *, double, std::vector <double> *, std::vector <double> *, std::vector <double> *);
