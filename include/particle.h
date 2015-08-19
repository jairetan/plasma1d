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

    public:
        Particle ()
        {
        }
        Particle (double m, double c, double v, double p, double w);
        double get_vel ();
        double get_pos ();
        void inc_pos (double);
        void inc_vel (double accel_left, double accel_right); //somehwo adapt for b field when time comes
        double get_mom ();
        double get_ke ();
        double get_width();
        double get_charge();
        double get_mass();
};


