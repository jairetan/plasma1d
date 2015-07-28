#include "density_diagnostic.h"

void density_diagnostic (std::vector <double> *density, int iter)
{
    std::string path = DATA_DIR + to_string (10*iter*D_T/T) + "density_out.dat";
    std::vector <double> x;
    for (int i = NUM_CELLS-1; i >=0; i--){
        x.push_back (i);
    }

    out_writer (path, &x, density);

}
