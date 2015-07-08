#include "proton.h"
#include "stdio.h"

Proton::Proton ()
{
    Proton (0,0,0);
}

Proton::Proton (double v, double p, double w)
    //:Particle(CLHEP::proton_mass_c2/CLHEP::c_squared, CLHEP::
                    //eplus, v, p, w)
    :Particle(P_MASS, P_CHARGE, v, p, w)
{
}
