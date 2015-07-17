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
        if (CIC){
            weighing (particles->at (i), weights);
        }
        else if (ZERO_ORDER){
            zero_order_weighing (particles->at (i), weights);
        }
        adjacent_points (particles->at (i), points);

        for (int j = 0; j < adjacencies; j++){
            //if (points[j] > NUM_CELLS-1 || points [j] < 0){
            //std::cout << points[j] << "\n";
            //exit (-1);
            //}
            density->at (points [j]) +=
                weights [j]* ((particles->at (i))->get_charge());
        }
    }
}
