//Return 1D positions vs time
#include "phase_diagnostic.h"

void phase_diagnostic (std::vector <Particle *> *particles, int iter)
{
    int size = particles -> size();
    FILE *file = NULL;
    std::string path = DATA_DIR + to_string (10*iter*D_T/T) + "phase_out.dat";

    if ((file = fopen (path.c_str(), "a")) == NULL){
        printf ("Error opening file");
        return;
    }

    for (int i = 0; i < size; i+=10){
        fprintf (file, "%f %f\n", particles->at (i)->get_pos(), particles->at (i)->get_vel());
    }

    fclose (file);
}
