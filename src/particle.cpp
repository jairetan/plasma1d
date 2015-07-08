#include "/home/jtan/Desktop/include/CLHEP/Units/PhysicalConstants.h"
#include "particle.h"
#include "jmod.h"

Particle:: Particle (double m, double c, double v, double p, double w)
: mass (m), charge (c), velocity (v), position (p), width (w)
{
}

double Particle::get_vel ()
{
    return velocity;
}

double Particle::get_pos ()
{
    return position;
}

void Particle::inc_pos (double dt, int num_cells)
{
    position = jmod (position + velocity * dt, num_cells);
}

double Particle::inc_vel (double dt, double field)
{
    //printf ("%.17f\n", (field * charge/mass));
    //printf ("Velocity: %.17f\n", velocity);
    //printf ("Field at %f: %.17f\n", position,  field);
    //printf ("Charge %f\n", charge);
    velocity += (field * charge/mass) * dt;
    //printf ("After: %.17f\n", velocity);
    return field;
}

double Particle::get_mom ()
{
    return mass * velocity;
}

double Particle::get_ke ()
{
    return mass * velocity * velocity / 2;
}

double Particle::get_width ()
{
    return width;
}

double Particle::get_charge()
{
    return charge;
}
