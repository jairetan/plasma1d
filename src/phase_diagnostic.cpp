//Return 1D positions vs time
#include "phase_diagnostic.h"

void phase_diagnostic (std::vector <Particle *> *particles, int iter)
{
    int size = particles -> size();
    std::string path = DATA_DIR + to_string (10*iter*D_T/T) + "phase_out.dat";
    std::ofstream phase_out (path.c_str(), std::ios::app);

    for (int i = 0; i < size; i+=10){
        phase_out << particles->at (i)->get_pos() << " " << particles->at (i)->get_vel() << "\n";
    }

    phase_out.close();
}
