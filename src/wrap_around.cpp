#include "wrap_around.h"
#include <cstdio>
double wrap_around (double position, double max_pos)
{
    if (position < 0){
        return position + max_pos;
    }

    else if (position >= max_pos){
        return position - max_pos;
    }

    return position;
}
