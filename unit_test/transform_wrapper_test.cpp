#include "transform_wrapper.h"
#include <gtest/gtest.h>

TEST (transform_wrapper_test, forward_transform)
{
    double input [4] = {5,-9,2,0};
    std::vector <std::complex <double> > output = transform (input, 4);
    full_transform (&output[0], 4);

    ASSERT_FLOAT_EQ (output [0].real (), -1);
    ASSERT_FLOAT_EQ (output [0].imag (), 0);
    ASSERT_FLOAT_EQ (output [1].real (), 1.5);
    ASSERT_FLOAT_EQ (output [1].imag (), 4.5);
    ASSERT_FLOAT_EQ (output [2].real (), 8);
    ASSERT_FLOAT_EQ (output [2].imag (), 0);
    ASSERT_FLOAT_EQ (output [3].real (), 1.5);
    ASSERT_FLOAT_EQ (output [3].imag (), -4.5);

}
TEST (transform_wrapper_test, reverse_transform)
{
    double input [5] = {3,2,2,-10,1};
    std::vector <std::complex <double> > transformed = transform (input, 5);
    std::vector <double> output = inverse_transform (&transformed[0], 5);

    ASSERT_FLOAT_EQ (output [0], input [0]);
    ASSERT_FLOAT_EQ (output [1], input [1]);
    ASSERT_FLOAT_EQ (output [2], input [2]);
    ASSERT_FLOAT_EQ (output [3], input [3]);
    ASSERT_FLOAT_EQ (output [4], input [4]);
}


