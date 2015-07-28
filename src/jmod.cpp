//True modulus
#include "jmod.h"

double jmod (const double x, const double y){
    double r = fmod(x, y);

    return r < 0 ? r+y : r;
}
