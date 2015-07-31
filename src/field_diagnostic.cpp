#include "field_diagnostic.h"

void field_diagnostic (std::vector <double> *field, int iter)
{
    std::vector <double> x;
    for (int i = NUM_CELLS-1; i >=0; i--){
        x.push_back (i);
    }
    std::string path = DATA_DIR + to_string (iter*D_T*10/T) +"field_out.dat";

    out_writer (path, &x, field);
}
