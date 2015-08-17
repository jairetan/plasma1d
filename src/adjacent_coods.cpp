//1 Dimension adjacent points
#include "adjacent_coods.h"

void adjacent_points (Particle *particle, int *points)
{
    auto left = (int) (wrap_around (particle->get_pos(), NUM_CELLS));
    auto right = (int) (wrap_around (particle->get_pos()+1, NUM_CELLS));

    points [1] = right;
    points [0] = left;
}
