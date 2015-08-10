//Move particles
#include "move.h"

//Return normalized acceleration
static double find_accel (double field, Particle *particle)
{
    double accel = FIELD_SCALE * field * particle->get_charge ()/particle->get_mass()
        *D_T*D_T/GRID_SIZE;

    return accel;
}

void move_particles (std::vector <Particle *> * particles,
        std::vector <double> *field)
{
    int num_particles = particles->size();
    double left_field = 0, right_field = 0, accel = 0;
    double *weights = new double [2];
    int *points = new int [2];

    for (int i = 0; i < num_particles; i++)
    {
        Particle *particle = particles->at (i);

        if (CIC){
            weighing (particle, weights);
        }
        else if (ZERO_ORDER){
            zero_order_weighing (particle, weights);
        }

        adjacent_points (particle, points);
        left_field = field->at (points [0]) * weights [0];
        right_field = field->at (points [1]) * weights [1];
        accel = find_accel(left_field + right_field, particle);

        particle->inc_vel (accel);
        particle->inc_pos ();
    }
}
