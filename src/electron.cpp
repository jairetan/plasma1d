#include "electron.h"

Electron::Electron ()
{
    Electron (0,0,0);
}

Electron::Electron (double v, double p, double w)
    //:Particle(CLHEP::electron_mass_c2/CLHEP::c_squared,
            //CLHEP::electron_charge, v, p, w)
    :Particle(E_MASS,
            E_CHARGE, v, p, w)
{
}
