//Return 1D positions vs time
#include "phase_diagnostic.h"

void phase_diagnostic (std::vector <Particle *> *particles, int iter)
{
    int size = particles->size();
    std::ofstream file;
    auto path = DATA_DIR + std::to_string (int (.5 +10*iter/ITERATIONS)) + "phase_out.dat";
    file.open (path.c_str (), std::ios::app);

    for (int i = 0; i < size; i++){
        file << particles->at (i)->get_pos() << " " <<
                particles->at (i)->get_vel() << std::endl;
    }

    file.close();
}
