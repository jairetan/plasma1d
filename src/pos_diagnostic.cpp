//Return 1D positions vs time
#include "pos_diagnostic.h"

void pos_diagnostic (std::vector <Particle *> *particles, double t)
{
    int size = particles -> size();
    std::string path = DATA_DIR + "pos_out.dat";
    std::ofstream pos_out (path.c_str(), std::ios::app);

    for (int i = 0; i < size; i+=10){
        pos_out << t << " " << particles->at (i)->get_pos() << "\n";
    }

    pos_out.close();
}
