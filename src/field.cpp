#include <complex.h>
#include "field.h"
#include <fstream>

//Mutliplier for transformed density
static double trans_mult (int x)
{
    //double multiplier =  inner_term*inner_term/sin (inner_term) / sin (inner_term)/k/k;
    double multiplier = -2*M_PI *1/(cos (2*M_PI*x/NUM_CELLS)-1);

    return multiplier;
}

//Calculate Electric field from finite differences
static void electric_field (std::vector <double> *phi, std::vector <double> *field)
{
    for (int i = 1 ; i < NUM_CELLS-1; i++)
    {
        field->at (i) = (phi->at (i-1)-phi->at (i+1))/2;
    }

    //Periodic boundary conditions
    field->at (0) = (phi->at (NUM_CELLS-1)-phi->at (1))/2;
    field->at (NUM_CELLS-1) = (phi->at(NUM_CELLS-2)-phi->at (0))/2;
}

//Calculate potential and electric field from charge density
void calc_field (std::vector <double> *field_vector,
        std::vector <double> *pot_vector,
        std::vector <double> *density_vector)
{
    double *potential = new double [NUM_CELLS];
    double *density = (double *)calloc (NUM_CELLS,
                   sizeof (double));

    fftw_complex *density_trans = NULL;
    fftw_plan p;

    density_trans = transform (&((*density_vector)[0]), NUM_CELLS);

    for (int x = 0; x < NUM_CELLS/2; x++)
    {
        density_trans [x] *= trans_mult (x);
    }

    density_trans [0] = 0; //automatically add in neutralizing background ions?

    p = fftw_plan_dft_c2r_1d (NUM_CELLS, density_trans,
            potential, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    /*divide by NUM_CELLS in array (inverse transform not normalized)*/
    for (int x = 0; x < NUM_CELLS; x++)
    {
        potential [x] /= NUM_CELLS;
        pot_vector->at (x) = potential [x];
    }

    electric_field (pot_vector, field_vector);
    free (density);
    free (potential);

    fftw_free (density_trans);
}
