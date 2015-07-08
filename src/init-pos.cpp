//Return random value between 1 and num_cells inclusive
#include "init-pos.h"

int random_start (int num_cells)
{
    //srand (time(NULL));
    //printf ("%d\n", rand());
    int pos = rand () % num_cells;
    return pos;
}
