//Electron particle
#include "particle.h"

#pragma once
#define E_CHARGE -1 //Normalized fundamental charge
#define E_MASS 1 //Normalized Electron mass

class Electron : public Particle
{
    public:
        Electron ();
        Electron (double v, double p, double w);
};
