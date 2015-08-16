#include "psd.h"
#include <cstdio>
#include <gtest/gtest.h>

TEST (complex_transform_wrapper_test, forward_transform)
{
    std::complex <double> input [4] = {std::complex <double> (5,0), std::complex <double> (-9,0),std::complex <double> (2,0),std::complex<double>(0,0)};
    printf ("%lf %lf %lf %lf\n", input[0].real(), input [1].real(), input [2].real(), input[3].real());
    std::complex <double> *output = complex_forward_trans (input, 4);
    full_transform (output, 4);
    printf ("%lf %lf %lf %lf\n", output[0].real(), output [1].real(), output [2].real(), output[3].real());

    double real_0 =  output  [0].real ()/2;
    double imag_0 =  output [0].imag ()/2;
    double real_1 =  output  [1].real ()/2;
    double imag_1 =  output [1].imag ()/2;
    double real_2 =  output  [2].real ()/2;
    double imag_2 =  output [2].imag ()/2;
    double real_3 =  output  [3].real ()/2;
    double imag_3 =  output [3].imag ()/2;

    EXPECT_DOUBLE_EQ (real_0, -1);
    EXPECT_DOUBLE_EQ (imag_0, 0);
    EXPECT_DOUBLE_EQ (real_1, 1.5);
    EXPECT_DOUBLE_EQ (imag_1, 4.5);
    EXPECT_DOUBLE_EQ (real_2, 8);
    EXPECT_DOUBLE_EQ (imag_2, 0);
    EXPECT_DOUBLE_EQ (real_3, 1.5);
    EXPECT_DOUBLE_EQ (imag_3, -4.5);
}
