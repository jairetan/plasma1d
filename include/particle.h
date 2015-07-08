//General object that occupies simulation
#include "/home/jtan/Desktop/include/CLHEP/Units/PhysicalConstants.h"

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
        void inc_pos (double dt, int);
        double inc_vel (double dt, double field); //somehwo adapt for b field when time comes
        double get_mom ();
        double get_ke ();
        double get_width();
        double get_charge();
};


