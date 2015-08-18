#include "density.h"
void calc_density (std::vector <Particle> *particles,
        std::vector <double> *grid_density)
{
    auto test = 0;
    auto num_particles = particles->size();
    auto adjacencies = pow (2, 1);

    std::vector <double> weights (2);
    std::vector <int> points (2);

    //#pragma omp parallel for
    for (auto &particle : *particles){
        auto particle_charge = particle.get_charge();

        if (CIC){
            weighing (&particle, &weights[0]);
        }
        else if (ZERO_ORDER){
            zero_order_weighing (&particle, &weights[0]);
        }

        adjacent_points (&particle, &points[0]);

        for (int j = 0; j < adjacencies; j++){
            grid_density->at (points [j]) += weights [j]* (particle_charge);
        }
    }
}
