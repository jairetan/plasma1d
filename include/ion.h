//Electron particle

#pragma once
#include "particle.h"
#include "parameters.h"

class Ion : public Particle
{
    public:
        Ion ();
        Ion (double v, double p, double w);
};
