//Electron particle

#pragma once
#include "particle.h"
#include "parameters.h"

class Electron : public Particle
{
    public:
        Electron ();
        Electron (double v, double p, double w);
};
