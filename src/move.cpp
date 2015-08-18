//Move particles
#include "move.h"
#include <iostream>

//Return normalized acceleration
static double find_accel (double field, Particle *particle)
{
    double accel = field * particle->get_charge ()/particle->get_mass()
        *D_T*D_T/GRID_SIZE;

    return accel;
}

void move_particles (std::vector <Particle> *particles,
        std::vector <double> *field)
{
    auto num_particles = particles->size();
    auto left_field = 0, right_field = 0, accel = 0;
    std::vector <double> weights (2);
    std::vector <int> points (2);

    for (auto &particle : *particles)
    {
        if (CIC){
            weighing (&particle, &weights[0]);
        }
        else if (ZERO_ORDER){
            zero_order_weighing (&particle, &weights[0]);
        }

        adjacent_points (&particle, &points[0]);
        left_field = field->at (points [0]) * weights [0];
        right_field = field->at (points [1]) * weights [1];
        accel = find_accel(left_field + right_field, &particle);

        particle.inc_pos ();
        particle.inc_vel (accel);
    }
}
