#include "velocity_diagnostic.h"

void velocity_diagnostic (std::vector <Particle *> *particles)
{
    std::string path = DATA_DIR + "vel_out.dat";
    std::ofstream vel_out (path.c_str(), std::ios::app);

    int size = particles->size();
    for (int i = 0; i < size; i+=50)
    {
        vel_out << i << " " << particles->at (i)->get_vel()<< "\n";
    }
    vel_out.close ();

}
