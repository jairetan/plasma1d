//Return random value between 1 and num_cells inclusive
#include <cstdio>
#include "init_pos.h"

int random_start ()
{
    //srand (time(NULL));
    //printf ("%d\n", rand());

    int pos = rand () % NUM_CELLS;
    if (pos < 0 || pos > NUM_CELLS){
        printf ("Seriously\n");
    }
    return pos;
}
