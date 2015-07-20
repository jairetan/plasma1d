#include "weighing.h"
void alt_weighing (Particle *particle, double *weights)
{
    double left_pos = 0, right_pos = 0, left_perc = 0, right_perc = 0;

    left_pos = particle->get_pos()-.5*particle->get_width();
    right_pos = left_pos + 1;

    weights [0] = (particle->get_pos () - right_pos);
    weights [1] = particle->get_pos () - left_pos;
}

//1D weighing scheme
void weighing (Particle *particle, double *weights)
{
    double left_pos = 0, left_perc = 0, right_perc = 0;

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
    weights[1] = (right_perc);
    weights[0] = (left_perc);
}
