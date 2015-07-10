//Return random value between 1 and num_cells inclusive
#include "init-pos.h"

int random_start ()
{
    //srand (time(NULL));
    //printf ("%d\n", rand());
    int pos = rand () % NUM_CELLS;
    return pos;
}
