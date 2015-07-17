#include "density_diagnostic.h"

void density_diagnostic (std::vector <double> *density, int iter)
{
    std::string path = DATA_DIR + to_string (10*iter*D_T/T) + "density_out.dat";
    std::ofstream density_out (path.c_str(), std::ios::app);
    for (int x = 0; x < NUM_CELLS; x++)
    {
        density_out << x << " " << density->at (x) << "\n";
    }
    density_out.close ();
}
