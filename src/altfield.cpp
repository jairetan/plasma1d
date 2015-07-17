#include <complex.h>
#include "altfield.h"
#include <iostream>

static double trans_mult (int x, double kappa)
{
    //double delta_x = SYS_SIZE/NUM_CELLS;
    //double k = kappa * x;
    //double inner_term = k * delta_x / 2;

    //double multiplier =  inner_term*inner_term/sin (inner_term) / sin (inner_term)/k/k;
    double multiplier = .5 *1/(cos (2*M_PI*x/NUM_CELLS)-1);
    if (cos(2*M_PI*x/NUM_CELLS)-1 == 0){
        std::cout << x << "\n";
        exit (-1);
    }
    return multiplier;
}

void electric_field (std::vector <double> *phi, std::vector <double> *field)
{
    for (int i = 1 ; i < NUM_CELLS-1; i++)
    {
        field->at (i) = (phi->at (i-1)-phi->at (i+1))/2;
    }

    //Periodic boundary conditions
    field->at (0) = (phi->at (NUM_CELLS-1)-phi->at (1))/2;
    field->at (NUM_CELLS-1) = (phi->at(NUM_CELLS-2)-phi->at (0))/2;
}

void calc_field (std::vector <double> *field_vector,
        std::vector <double> *pot_vector,
        std::vector <double> *density_vector)
{
    double *potential = (double *)calloc (NUM_CELLS,
            sizeof (double)),
           *density = (double *)calloc (NUM_CELLS,
                   sizeof (double));

    double kappa = 2*M_PI/NUM_CELLS;
    fftw_complex *pot_trans = NULL;
    fftw_plan p;

    for (int i = 0; i < NUM_CELLS; i++){
        density [i] = density_vector->at(i);
    }

    pot_trans = (fftw_complex*) fftw_malloc
        (sizeof (fftw_complex)*(NUM_CELLS/2+1)); //Efficiency of fftw3

    /*Transform density*/
    p = fftw_plan_dft_r2c_1d
        (NUM_CELLS, density, pot_trans, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    for (int x = 1; x < NUM_CELLS/2+1; x++)
    {
        //pot_trans [x] *= -1/ (x*x)/.1 / kappa /kappa;
        pot_trans [x] *= trans_mult (x, kappa);
    }

    //pot_trans [0] *= trans_mult (NUM_CELLS, kappa);
    pot_trans [0] = 0; //Making 0 doesn't seem to affect field calc

    p = fftw_plan_dft_c2r_1d (NUM_CELLS, pot_trans,
            potential, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    /*divide by NUM_CELLS in array (inverse transform not normalized)*/
    for (int x = 0; x < NUM_CELLS; x++)
    {
        potential [x] /= -NUM_CELLS;
        pot_vector->at (x) = potential [x];
    }

    electric_field (pot_vector, field_vector);
    free (potential);
    free (density);

    fftw_free (pot_trans);
}
