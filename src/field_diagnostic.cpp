#include "field_diagnostic.h"
#include "parameters.h"

void field_diagnostic (std::vector <double> *field)
{
    std::ofstream field_out ("field_out.dat", std::ios::app);
    int size = field->size();
    for (int x = 0; x < size; x++)
    {
        field_out << x << " " << field->at (x) << "\n";
    }
    field_out.close ();
}
