//Move particles
#include "move.h"
#include <fstream>

//Return normalized acceleration
static double find_accel (double field, Particle *particle)
{
    double dx = SYS_SIZE/NUM_CELLS;
    double accel = FIELD_SCALE* field * particle->get_charge () *D_T *D_T / particle->get_mass ()/ dx;
    //std::ofstream field_test ("field_test.dat", std::ios::app);
    //field_test << "Field" << field << "\n";
    //field_test.close();
    return accel;
}

void move_particles (std::vector <Particle *> * particles, std::vector <double> *field)
{
    int num_particles = particles->size();
    double left_field = 0, right_field = 0, accel = 0;
    double *weights = new double [2];
    int *points = new int [2];

    for (int i = 0; i < num_particles; i++)
    {
        weighing (particles->at (i), weights);
        //zero_order_weighing (particles->at (i), &weights); //Birdsell says to conserve energy
        adjacent_points (particles->at (i), points);
        left_field = field->at (points [0])*weights [0];
        right_field = field->at (points[1]) * weights [1];
        accel = find_accel(left_field+right_field, particles->at (i));

        particles->at (i)->inc_vel (accel);
        particles->at (i)->inc_pos ();
    }
}
