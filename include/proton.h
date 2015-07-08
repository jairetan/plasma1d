//Proton class
#include "particle.h"

#pragma once
#define P_CHARGE 10000
#define P_MASS .1

class Proton : public Particle
{
    public:
        Proton ();
        Proton (double v, double p, double w);
};
