#include <vector>
#include "density_diagnostic.h"
#include "pot_diagnostic.h"
#include "velocity_diagnostic.h"
#include "field_diagnostic.h"
#include "phase_diagnostic.h"
#include "particle.h"
#include "psd.h"

void snapshot_diagnostics (std::vector <Particle *> *, std::vector <double> *, std::vector <double> *, std::vector <double> *, int);
