//Return random value between 1 and num_cells inclusive
#include "init_pos.h"

int random_start ()
{
    //srand (time(NULL));
    //printf ("%d\n", rand());
    int pos = rand () % NUM_CELLS/2;
    return pos;
}
