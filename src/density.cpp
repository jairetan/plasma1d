#include "density.h"

void calc_density (std::vector <double> *density, std::vector <Particle *> *particles)
{
    //Change to any dimension later on
    int num_particles = particles->size(), adjacencies = pow (2, 1);
    double *weights = new double [2];
    int *points = new int[2];

    //Reset density
    for (int i = 0; i < NUM_CELLS; i++){
        density->at (i) = 0;
    }

    for (int i = 0; i < num_particles; i++){
        Particle *particle = particles->at (i);
        double particle_charge = particle->get_charge();

        if (CIC){
            weighing (particle, weights);
        }
        else if (ZERO_ORDER){
            zero_order_weighing (particle, weights);
        }
        adjacent_points (particle, points);

        for (int j = 0; j < adjacencies; j++){
            density->at (points [j]) +=
                weights [j]* (particle_charge);
        }
    }
}
