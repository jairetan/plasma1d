#include "snapshot_diagnostics.h"
void snapshot_diagnostics (std::vector <Particle *> *particles,
        std::vector <double> *density, std::vector <double> *field,
        std::vector <double> *potential, int iter)
{
    density_diagnostic (density, iter);
    field_diagnostic (field, iter);
    field_space_transform (field, iter);
    pot_diagnostic (potential, iter);
    phase_diagnostic (particles, iter);
    U_psd (potential, density, iter);
}
