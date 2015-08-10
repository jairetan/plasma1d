//1 Dimension adjacent points
#include <cstdio>
#include "adjacent_coods.h"

void adjacent_points (Particle *particle, int *points)
{
    int left = (int) wrap_around (particle->get_pos(), NUM_CELLS);
    int right = (int) wrap_around (particle->get_pos()+1, NUM_CELLS);

    points [1] = right;
    points [0] = left;
}
