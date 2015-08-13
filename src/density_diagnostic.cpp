#include "density_diagnostic.h"

void density_diagnostic (std::vector <double> *density, const int iter)
{
    std::string path = DATA_DIR + to_string (int (.5+10*iter/ITERATIONS)) + "density_out.dat";
    std::vector <double> x;

    for (int i = NUM_CELLS-1; i >=0; i--){
        x.push_back (i);
    }

    out_writer (path, &x, density);

}
