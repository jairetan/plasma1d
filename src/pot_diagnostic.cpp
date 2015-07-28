#include "pot_diagnostic.h"

void pot_diagnostic (std::vector <double> *pot, int iter)
{
    std::vector <double> x;
    for (int i = NUM_CELLS-1; i >=0; i--){
        x.push_back (i);
    }

    std::string path = DATA_DIR + to_string (iter*10*D_T/T) + "pot_out.dat";

    out_writer (path, &x, pot);
}

