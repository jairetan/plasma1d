#include "pot_diagnostic.h"

void pot_diagnostic (std::vector <double> *pot, int iter)
{
    std::string path = DATA_DIR + to_string (iter*10*D_T/T) + "pot_out.dat";
    std::ofstream pot_out (path.c_str(), std::ios::app);
    int size = pot->size();

    for (int x = 0; x < size; x++)
    {
        pot_out << x << " " << pot->at (x) << "\n";
    }

    pot_out.close ();
}

