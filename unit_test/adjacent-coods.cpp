//1 Dimensino adjacent points
#include "adjacent-coods.h"
#include "particle.h"
#include "electron.h"
#include <iostream>

void adjacent_points_run ()
{
    std::vector <int> points (2);
    std::vector <int> points2 (2);
    Electron e (0, 5.5, 1);
    Electron e2 (0, 10, 1);

    adjacent_points (&e, &points);
    adjacent_points (&e2, &points2);
    if (points.at (0) != 5 || points.at (1) != 6
            || points2. at (0) != 10 || points2.at (0) != 11){
        std::cout << "adjacent coods fail\n";
    }
}

void adjacent_points (Particle *particle, std::vector <int> *points)
{
    int left = (int)jmod (particle->get_pos(), NUM_CELLS);
    int right = (int)jmod (particle->get_pos()+1, NUM_CELLS);

    //points->insert (points->begin(), left); //to the left or where the particle is
    //points->insert (points->begin()+1, right);

    points->push_back (right);
    points->push_back (left);
}
