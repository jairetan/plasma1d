//Move particles
#include "move.h"
#include <iostream>

//Return normalized acceleration
static double find_accel (double field, Particle *particle)
{
    double dx = SYS_SIZE/NUM_CELLS;
    double accel = FIELD_SCALE* field * particle->get_charge () *D_T *D_T / particle->get_mass ()/ dx;
    return accel;
}

void move_particles (std::vector <Particle *> * particles, std::vector <double> *field)
{
    using namespace std;

    int num_particles = particles->size();
    vector <double> weights;
    vector <int> points;

    for (int i = 0; i < num_particles; i++)
    {
        weighing (particles->at (i), &weights);
        //zero_order_weighing (particles->at (i), &weights); //Birdsell says to conserve energy
        adjacent_points (particles->at (i), &points);

        particles->at (i)->inc_vel (find_accel(field->at (points.at (0))*weights.at (0)+field->at (points.at (1))*weights.at (1), particles->at(i)));
        particles->at (i)->inc_pos ();

        weights.clear();
        points.clear ();
    }
}
