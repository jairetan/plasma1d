#include "pot_diagnostic.h"

void pot_diagnostic (std::vector <double> *pot, int iter)
{
    std::vector <double> x (NUM_CELLS);
    for (int i = 0; i < NUM_CELLS; i++){
        x[i] = i;
    }

    auto path = DATA_DIR + std::to_string (int (.5 +iter*10/ITERATIONS)) +
        "pot_out.dat";

    out_writer (path, &x, pot);
}

