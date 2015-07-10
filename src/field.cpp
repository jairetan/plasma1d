//Calculate field with fftw
#include "field.h"

void calc_field (std::vector <double> *field_vector,
        std::vector <double> *pot_vector,
        std::vector <double> *density_vector)
{
    double *field = (double *)calloc (NUM_CELLS,
            sizeof (double)),
           *potential = (double *)calloc (NUM_CELLS,
            sizeof (double)),
           *density = (double *)calloc (NUM_CELLS,
                   sizeof (double));

    fftw_complex *e_trans = NULL, *pot_trans = NULL;
    fftw_plan p;

    for (int i = 0; i < NUM_CELLS; i++){
        density [i] = density_vector->at(i);
    }

    e_trans = (fftw_complex*) fftw_malloc
        (sizeof (fftw_complex)*(NUM_CELLS));
    pot_trans = (fftw_complex*) fftw_malloc
    (sizeof (fftw_complex)*(NUM_CELLS+1));

    /*Transform density*/
    p = fftw_plan_dft_r2c_1d
        (NUM_CELLS, density, e_trans, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    /*Obtain potential transform*/
    /*phi_k = 4pi/(1-cos (2pik/N))*/
    pot_trans [0] = e_trans [0];
    pot_trans [0] *= 4*M_PI / (1 - cos (2*M_PI*NUM_CELLS)/(NUM_CELLS+1));

    /*wrap around*/
    e_trans[0] *= 4*M_PI/(I*sin (2*M_PI*(NUM_CELLS-1)/(NUM_CELLS)));

    /*Dividing by 0?*/
    for (int x = 1; x < NUM_CELLS; x++)
    {
        pot_trans[x] = e_trans [x];
        pot_trans [x] *= 4*M_PI / (1-cos (2*M_PI*x)/(NUM_CELLS+1));

        e_trans [x] *= 4*M_PI/(I*sin (2*M_PI*x/(NUM_CELLS)));
    }

    p = fftw_plan_dft_c2r_1d (NUM_CELLS, e_trans,
            field, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    p = fftw_plan_dft_c2r_1d (NUM_CELLS, pot_trans,
            potential, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    /*divide by num_cells in array (inverse transform not normalized)*/
    for (int x = 0; x < NUM_CELLS; x++)
    {
        field[x] /= NUM_CELLS;
        potential [x] /= -NUM_CELLS;
        field_vector->at (x) =field[x];
        pot_vector->at (x) = potential [x];

    }
    free (potential);
    free (field);
    free (density);

    fftw_free (e_trans);
    fftw_free (pot_trans);
}
