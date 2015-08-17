#include "density.h"

static void reset_density (std::vector <double> *grid_density)
{
    for (auto &point_density : *grid_density){
        point_density = BACKGROUND_DENSITY;
    }

    //for (auto i = 0; i < NUM_CELLS; i++){
        //density->at (i) = BACKGROUND_DENSITY;
    //}
}

void calc_density (std::vector <Particle *> *particles,
        std::vector <double> *grid_density)
{
    auto test = 0;
    auto num_particles = particles->size();
    auto adjacencies = pow (2, 1);

    std::vector <double> weights (2);
    std::vector <int> points (2);

    reset_density (grid_density);

    //#pragma omp parallel for
    for (int i = 0; i < num_particles; i++){
        auto particle = particles->at (i);
        auto particle_charge = particle->get_charge();

        //Weighing schemes
        if (CIC){
            weighing (particle, &weights[0]);
        }
        else if (ZERO_ORDER){
            zero_order_weighing (particle, &weights[0]);
        }

        adjacent_points (particle, &points[0]);

        for (int j = 0; j < adjacencies; j++){
            grid_density->at (points [j]) += weights [j]* (particle_charge);
        }
    }
}
