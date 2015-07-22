#include "snapshot_diagnostics.h"
void snapshot_diagnostics (std::vector <Particle *> *particles,
        std::vector <double> *density, std::vector <double> *field, std::vector <double> *potential, int i)
{
    density_diagnostic (density, i);
    field_diagnostic (field, i);
    pot_diagnostic (potential, i);
    velocity_diagnostic (particles, i);
    phase_diagnostic (particles, i);
}
