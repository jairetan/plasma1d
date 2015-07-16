#include "electron.h"

Electron::Electron ()
{
    Electron (0,0,0);
}

Electron::Electron (double v, double p, double w)
    :Particle (ELECTRON_MASS,ELECTRON_CHARGE, v, p, w)
{
}
