//Return random value between 1 and num_cells inclusive
#include <cstdio>
#include "init_pos.h"

int random_start ()
{
    //srand (time(NULL));
    //printf ("%d\n", rand());

    return rand () % NUM_CELLS;
}
