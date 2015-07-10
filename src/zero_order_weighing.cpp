#include "zero_order_weighing.h"
void zero_order_weighing (Particle *particle, std::vector <double> *weights)
{
    int nearest = (int)(particle->get_pos() + .5);
    double left_perc, right_perc;
    if (nearest < particle->get_pos()){
        left_perc = 1.;
        right_perc = 0.;
    }
    else{
        right_perc = 1.;
        left_perc = 0.;
    }

    weights->push_back (right_perc);
    weights->push_back (left_perc);
}
