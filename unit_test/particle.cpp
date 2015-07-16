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
    position = jmod (position + velocity, NUM_CELLS);
}

//Increment velocity relative to grid points
void Particle::inc_vel (double accel)
{
    //printf ("%.17f\n", (field * charge/mass));
    //printf ("Velocity: %.17f\n", velocity);
    //printf ("Field at %f: %.17f\n", position,  field);
    //printf ("Charge %f\n", charge);
    //double v_orig = velocity; if (accel == 0) {
        ////std::cout << "it's zero\n";
        //return;
    //}
    velocity += accel;
    //if (fabs (v_orig-velocity) > accel +1e30){
        //std::cout <<"Inconsistent diff" << "\n";
        //std::cout << "Vel:" <<  v_orig << ":: Accel: " <<accel<<  "vs " << velocity;
        //exit (-1);
    //}

    //if (velocity > 1e8){
        //std::cout << velocity << "\n";
    //}
    //printf ("After: %.17f\n", velocity);
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
