//Move particles
#include "move.h"
#include <stdlib.h>
#include <stdio.h>

void move_particles (std::vector <Particle *> * particles, std::vector <double> *field, double dt, int num_cells)
{
    using namespace std;

    int num_particles = particles->size();
    vector <double> weights;
    vector <int> points;

    for (int i = 0; i < num_particles; i++)
    {

        weighing (particles->at (i), &weights);
        adjacent_points (particles->at (i), &points, num_cells);
        particles->at (i)->inc_vel (dt, field->at (points.at (0))*weights.at (0));
        particles->at (i)->inc_vel (dt, field->at (points.at (1))*weights.at (1));
        particles->at (i)->inc_pos (dt, num_cells);

        weights.clear();
        points.clear ();
    }

}
