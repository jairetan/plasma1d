#include "field_diagnostic.h"
#include <iostream>

void field_diagnostic (std::vector <double> *field, int iter)
{
    std::vector <double> x (NUM_CELLS);
    for (int i = 0; i < NUM_CELLS; i++){
        x [i] = i;
    }

    std::string path = DATA_DIR +
        to_string (int (.5 + iter*10/ITERATIONS)) +"field_out.dat";

    out_writer (path, &x, field);
}

void field_space_transform (std::vector <double> *field, int iter)
{
    auto space_transform = transform (&(field->at (0)), field->size());

    for (int i = 0 ; i < NUM_CELLS/5; i++){
        std::string path = DATA_DIR + to_string (i) + "field_space_trans.dat";

        std::ofstream file;
        file.open (path.c_str(), std::ios::app);

        file << iter << " " <<  space_transform [i].real() << " " <<
                space_transform[i].imag() << std::endl;

        file.close();
    }
}
