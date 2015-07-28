//General object that occupies simulation
#include "/home/jtan/Desktop/include/CLHEP/Units/PhysicalConstants.h"
#include "wrap_around.h"
#include "parameters.h"

#pragma once
class Particle
{
    protected:
        double mass;
        double charge;
        double velocity;
        double position;
        double width;

        Particle (double m, double c, double v, double p, double w);

    public:

        Particle ()
        {
        }
        double get_vel ();
        double get_pos ();
        void inc_pos ();
        void inc_vel (double); //somehwo adapt for b field when time comes
        double get_mom ();
        double get_ke ();
        double get_width();
        double get_charge();
        double get_mass();
};


