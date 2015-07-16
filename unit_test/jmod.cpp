//True modulus
#include "jmod.h"

double jmod (double x, double y){
    double r = fmod(x, y);

    return r < 0 ? r+y : r;
}
