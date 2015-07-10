//1 Dimensino adjacent points
#include <adjacent-coods.h>

void adjacent_points (Particle *particle, std::vector <int> *points)
{
    int left = (int)jmod (particle->get_pos(), NUM_CELLS);
    int right = (int)jmod (particle->get_pos()+1, NUM_CELLS);

    //points->insert (points->begin(), left); //to the left or where the particle is
    //points->insert (points->begin()+1, right);

    points->push_back (right);
    points->push_back (left);
}
