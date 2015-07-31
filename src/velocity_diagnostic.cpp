#include "velocity_diagnostic.h"

void velocity_diagnostic (std::vector <Particle *> *particles, int iter)
{
    std::string path = DATA_DIR +to_string (10*iter*D_T/T)+ "vel_out.dat";
    FILE *file = NULL;

    if ((file = fopen (path.c_str (), "a")) == NULL ){
        printf ("Error opening file");
    }

    int size = particles->size();
    for (int i = 0; i < size; i+=50)
    {
        fprintf (file, "%d %f\n", i, particles->at (i)->get_vel());
    }

    fclose (file);

}
