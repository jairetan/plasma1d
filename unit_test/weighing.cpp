//1D weighing scheme
#include "weighing.h"

void weighing (Particle *particle, std::vector <double> * weights)
{
    double left_pos = 0, left_perc = 0, right_perc = 0;
    using namespace std;

    left_pos = particle->get_pos()-.5*particle->get_width();
    left_perc = ((int)particle->get_pos() + .5 -left_pos)/particle->get_width();

    if (left_perc > 1)
    {
        left_perc = 1;
    }
    else if (left_perc < 0)
    {
        left_perc = 0;
    }

    right_perc = 1-left_perc;

    //weights->insert (weights->begin(), left_perc);
    //weights->insert (weights->begin()+1, right_perc);
    weights->push_back (right_perc);
    weights->push_back (left_perc);
}