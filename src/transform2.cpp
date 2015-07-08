
// Functions to calculate Fourier transforms of real data
// // using fftw Fast-Fourier-Transform routine.
// // Input/ouput arrays are assumed to be of extent J.
// // Calculates Fourier transform of array f in arrays Fr and Fi
void fft_forward (Array<double,1> f, Array<double,1>&Fr,
        Array<double,1>& Fi)
{
    fftw_complex ff[J], FF[J];
    //
    //           // Load data
    for (int j = 0; j < J; j++)
    {
        c_re (ff[j]) = f(j); c_im (ff[j]) = 0.;
    }
    //
    //                             // Call fftw routine
    fftw_plan p = fftw_create_plan (J, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_one (p, ff, FF);
    fftw_destroy_plan (p);

    //                                     // Unload data
    for (int j = 0; j < J; j++)
    {
        Fr(j) = c_re (FF[j]); Fi(j) = c_im (FF[j]);
    }
    //
    //                                                       // Normalize data
    Fr /= double (J);
    Fi /= double (J);
}

//                                                           // Calculates inverse Fourier transform of arrays Fr and Fi in array f
void fft_backward (Array<double,1> Fr, Array<double,1> Fi,
        Array<double,1>& f)
{
    fftw_complex ff[J], FF[J];
    //
    //                                                                     // Load data
    for (int j = 0; j < J; j++)
    {
        c_re (FF[j]) = Fr(j); c_im (FF[j]) = Fi(j);
    }
    //
    //                                                                                       // Call fftw routine
    fftw_plan p = fftw_create_plan (J, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_one (p, FF, ff);
    fftw_destroy_plan (p);

    //                                                                                               // Unload data
    for (int j = 0; j < J; j++)
        f(j) = c_re (ff[j]);
}
//
//                                                                                                       // Solves 1-d Poisson equation:
//                                                                                                       //    d^u / dx^2 = v   for  0 <= x <= L
//                                                                                                       // Periodic boundary conditions:
//                                                                                                       //    u(x + L) = u(x),  v(x + L) = v(x)
//                                                                                                       // Arrays u and v assumed to be of length J.
//                                                                                                       // Now, jth grid point corresponds to
//                                                                                                       //    x_j = j dx  for j = 0,J-1
//                                                                                                       // where dx = L / J.
//                                                                                                       // Also,
//                                                                                                       //    kappa = 2 pi / L
//
void Poisson1D (Array<double,1>& u, Array<double,1> v, double kappa)
{
    //                                                                                                         // Declare local arrays.
    Array<double,1> Vr(J), Vi(J), Ur(J), Ui(J);

    //                                                                                                             // Fourier transform source term
    fft_forward (v, Vr, Vi);

    //                                                                                                                 // Calculate Fourier transform of u
    Ur(0) = Ui(0) = 0.;
    for (int j = 1; j <= J/2; j++)
    {
        Ur(j) = - Vr(j) / double (j * j) / kappa / kappa;
        Ui(j) = - Vi(j) / double (j * j) / kappa / kappa;
    }
    for (int j = J/2; j < J; j++)
    {
        Ur(j) = Ur(J-j);
        Ui(j) = - Ui(J-j);
    }

    //                                                                                                                                                                 // Inverse Fourier transform to obtain u
    fft_backward (Ur, Ui, u);
}
