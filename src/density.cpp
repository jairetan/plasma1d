#include "density.h"
#include <cstdio>

static void reset_density (std::vector <double> *density)
{
    for (int i = 0; i < NUM_CELLS; i++){
        density->at (i) = BACKGROUND_DENSITY;
    }
}

void calc_density (std::vector <Particle *> *particles,
        std::vector <double> *density)
{
    //Change to any dimension later on
    int num_particles = particles->size(), adjacencies = pow (2, 1);
    double *weights = new double [2];
    int *points = new int [2];

    reset_density (density);

    for (int i = 0; i < num_particles; i++){
        Particle *particle = particles->at (i);
        double particle_charge = particle->get_charge();

        //Weighing schemes
        if (CIC){
            weighing (particle, weights);
        }
        else if (ZERO_ORDER){
            zero_order_weighing (particle, weights);
        }

        adjacent_points (particle, points);

        for (int j = 0; j < adjacencies; j++){
            if (points [j] > NUM_CELLS-1 || points [j] <0){
                printf ("%d AHHHH\n", points [j]);
            }
            density->at (points [j]) += weights [j]* (particle_charge);
        }
    }
}
