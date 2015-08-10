#include "particle.h"
#include <cstdio>


//All quantities natively normalized

Particle:: Particle (double m, double c, double v, double p, double w)
: mass (m), charge (c), velocity (v), position (p), width (w)
{
}

double Particle::get_vel ()
{
    return velocity;// * SYS_SIZE/NUM_CELLS/D_T;
}

double Particle::get_pos ()
{
    return position;
}

void Particle::inc_pos ()
{
    position = wrap_around (position + velocity, NUM_CELLS);
    if (position > 2*NUM_CELLS || position < -NUM_CELLS){
        printf ("Position: %f | Velocity: %f\n", position, velocity);
    }

}

//Increment velocity relative to grid points
void Particle::inc_vel (double accel)
{
    velocity += accel;
}

double Particle::get_mom ()
{
    return mass * velocity ; //* GRID_SIZE/ D_T; //denomarlize momentum
}

double Particle::get_ke ()
{
    return mass * velocity * velocity / 2 ;//* GRID_SIZE*GRID_SIZE/D_T/D_T; //denormalize
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
