#include "density.h"

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
    int i;

    reset_density (density);

    //#pragma omp parallel for
    for (i = 0; i < num_particles; i++){
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
            density->at (points [j]) += weights [j]* (particle_charge);
        }
    }

    delete [] weights;
    delete [] points;
}
