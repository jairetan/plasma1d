//1 Dimensino adjacent points
#include <iostream>
#include <stdlib.h>
#include "adjacent_coods.h"

void adjacent_points (Particle *particle, int *points)
{
    int left = (int)jmod (particle->get_pos(), NUM_CELLS);      //round down
    int right = (int)jmod (particle->get_pos()+1, NUM_CELLS);   //round up position

    //points->insert (points->begin(), left); //to the left or where the particle is
    //points->insert (points->begin()+1, right);

    points [1] = right;
    points [0] = left;
}
