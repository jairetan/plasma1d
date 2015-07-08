#include "altfield.h"

void electric_field (std::vector <double> *phi, std::vector <double> *field, int num_cells)
{
    for (int i = 1 ; i < num_cells-1; i++)
    {
        field->at (i) = (phi->at (i-1)-phi->at (i+1))/2;
    }

    //Periodic boundary conditions
    field->at (0) = (phi->at (num_cells-1)-phi->at (1))/2;
    field->at (num_cells-1) = (phi->at(num_cells-2)-phi->at (0))/2;
}

void calc_field (std::vector <double> *field_vector,
        std::vector <double> *pot_vector,
        std::vector <double> *density_vector, int num_cells)
{
    double *potential = (double *)calloc (num_cells,
                sizeof (double)),
           *density = (double *)calloc (num_cells,
                sizeof (double));

    double kappa = 2*M_PI/num_cells;
    fftw_complex *pot_trans = NULL;
    fftw_plan p;

    for (int i = 0; i < num_cells; i++){
        density [i] = density_vector->at(i);
    }

    pot_trans = (fftw_complex*) fftw_malloc
        (sizeof (fftw_complex)*(num_cells));

    /*Transform density*/
    p = fftw_plan_dft_r2c_1d
        (num_cells, density, pot_trans, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    /*Obtain potential transform*/
    pot_trans [0] = 0;

    //Why split up?
    for (int x = 1; x < num_cells; x++)
    {
        pot_trans [x] *= -1/ (x*x) / kappa /kappa;
    }
    //for (int x = num_cells/2; x < num_cells; x++){
        //pot_trans [x] = conj(pot_trans [num_cells-x]);
    //}

    p = fftw_plan_dft_c2r_1d (num_cells, pot_trans,
            potential, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    /*divide by num_cells in array (inverse transform not normalized)*/
    for (int x = 0; x < num_cells; x++)
    {
        potential [x] /= num_cells;
        pot_vector->at (x) = potential [x];
    }

    electric_field (pot_vector, field_vector, num_cells);
    free (potential);
    free (density);

    fftw_free (pot_trans);
}
