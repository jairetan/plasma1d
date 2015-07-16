#include "unit_run.h"

void move_particles_run();
void calc_field_run();
void calc_density_run();

int main()
{
    calc_density_run();
    calc_field_run();
    move_particles_run();
}
