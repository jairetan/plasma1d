#include "density.h"
#include <stdio.h>
#include "electron.h"
#include <vector>
#include <stdlib.h>

void calc_density_run ()
{
    std::vector <Particle *> particles;
    std::vector <double> density (4);

    Electron e (-.1, 0, 1);
    Electron e2 (0, 1, 1);
    Electron e3 (.1, 1.5, 1);
    Electron e4 (0, 2, 1);

    particles.push_back (&e);
    particles.push_back (&e2);
    particles.push_back (&e3);
    particles.push_back (&e4);

    calc_density (&density, &particles);

    if (!(density.at(0) == -1
                && density.at (1) == -1.5
                && density.at (2) == -1.5
                && density.at (3) == 0)){
            std::cout << "Density error\n";
            std::cout << density.at (0) << " " << density.at (1) <<
                " " << density.at (2) << " " << density.at (3);
            exit (-1);
    }
}

void calc_density (std::vector <double> *density, std::vector <Particle *> *particles)
{

    //Change to any dimension later on
    int num_particles = particles->size(), adjacencies = pow (2, 1);
    std::vector <double> weights;
    std::vector <int> points;

    ////Reset density
    //for (int i = 0; i < NUM_CELLS; i++){
        //density->at (i) = 0;
    //}

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

