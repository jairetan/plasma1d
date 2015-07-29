#include "particle.h"
#include <iostream>
#include <stdlib.h>

//All quantities natively normalized

Particle:: Particle (double m, double c, double v, double p, double w)
: mass (m), charge (c), velocity (v), position (p), width (w)
{
}

double Particle::get_vel ()
{
    return velocity; //* SYS_SIZE/NUM_CELLS/D_T;
}

double Particle::get_pos ()
{
    return position;
}

void Particle::inc_pos ()
{
    position = wrap_around (position + velocity, NUM_CELLS);
}

//Increment velocity relative to grid points
void Particle::inc_vel (double accel)
{
    velocity += accel;
}

double Particle::get_mom ()
{
    double dx = SYS_SIZE/NUM_CELLS;
    return mass * velocity * dx/ D_T; //denomarlize momentum
}

double Particle::get_ke ()
{
    double dx = SYS_SIZE/NUM_CELLS;
    return mass * velocity * velocity / 2 * dx*dx/D_T/D_T; //denormalize
}

double Particle::get_width ()
{
    return width;
}

double Particle::get_charge()
{
    return charge;
}
double Particle::get_mass()
{
    return mass;
}
