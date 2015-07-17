#include "weighing.h"
void weighing (Particle *particle, double *weights)
{
    double left_pos = 0, right_pos = 0, left_perc = 0, right_perc = 0;

    left_pos = particle->get_pos()-.5*particle->get_width();
    right_pos = left_pos + 1;

    weights [0] = particle->get_pos () - right_pos;
    weights [1] = particle->get_pos () - left_pos;
}
