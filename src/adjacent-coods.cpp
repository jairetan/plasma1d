//1 Dimensino adjacent points
#include <adjacent-coods.h>

void adjacent_points (Particle *particle, std::vector <int> *points, int num_cells)
{
    int left = (int)jmod (particle->get_pos(), num_cells);
    int right = (int)jmod (particle->get_pos()+1, num_cells);

    //points->insert (points->begin(), left); //to the left or where the particle is
    //points->insert (points->begin()+1, right);

    points->push_back (right);
    points->push_back (left);
}
