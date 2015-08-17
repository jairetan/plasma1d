#include "density.h"

static void reset_density (std::vector <double> *density)
{
    for (auto &i : *density){
        i = BACKGROUND_DENSITY;
    }

    //for (auto i = 0; i < NUM_CELLS; i++){
        //density->at (i) = BACKGROUND_DENSITY;
    //}
}

void calc_density (std::vector <Particle *> *particles,
        std::vector <double> *density)
{
    auto test = 0;
    //Change to any dimension later on
    auto num_particles = particles->size();
    auto adjacencies = pow (2, 1);
    auto *weights = new double [2];
    auto *points = new int [2];

    reset_density (density);

    //#pragma omp parallel for
    for (int i = 0; i < num_particles; i++){
        auto particle = particles->at (i);
        auto particle_charge = particle->get_charge();

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
