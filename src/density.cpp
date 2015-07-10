#include "density.h"
#include <stdio.h>

void calc_density (std::vector <double> *density, std::vector <Particle *> *particles)
{
    using namespace std;

    //Change to any dimension later on
    int num_particles = particles->size(), adjacencies = pow (2, 1);
    vector <double> weights;
    vector <int> points;

    //Reset density
    for (int i = 0; i < density->size(); i++){
        density->at (i) = 0;
    }

    for (int i = 0; i < num_particles; i++){
        weighing (particles->at (i), &weights);
        adjacent_points (particles->at (i), &points);

        for (int j = 0; j < adjacencies; j++){
            density->at (points.at (j)) +=
                weights.at (j)* ((particles->at (i))->get_charge());
        }

        weights.clear ();
        points.clear ();
    }
}

