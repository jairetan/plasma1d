#include "diagnostics.h"
void diagnostics (std::vector <Particle *> *particles, double t,
        std::vector <double> *potential, std::vector <double> *density)
{
    ke_diagnostic (particles, t);
    pe_diagnostic (potential, density, t);
    mom_diagnostic (particles, t);
    pos_diagnostic (particles, t);

}

