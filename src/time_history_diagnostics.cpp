#include "time_history_diagnostics.h"
void time_history_diagnostics (std::vector <Particle> *particles, double t,
        std::vector <double> *potential, std::vector <double> *density,
        std::vector <double> *field)
{
    energy_diagnostic (particles, potential, density,t);
    mom_diagnostic (particles, t);
    mode_diagnostic (potential,density, t);
}

