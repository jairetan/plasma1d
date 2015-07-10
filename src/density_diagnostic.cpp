#include "density_diagnostic.h"

void density_diagnostic (std::vector <double> *density)
{
    std::ofstream density_out ("density_out.dat", std::ios::app);
    int size = density->size();
    for (int x = 0; x < size; x++)
    {
        density_out << x << " " << density->at (x) << "\n";
    }
    density_out.close ();
}
