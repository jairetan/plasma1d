#include "weighing_test.h"

TEST (weighing_test, LeftBound){
    double *weights = new double [2];
    Ion *particle = new Ion (0,0,1);
    weighing (particle, weights);
    ASSERT_EQ (weights [0], 1);
    ASSERT_EQ (weights [1], 0);
}

TEST (weighing_test, RightBound){
    double *weights = new double [2];
    Ion *particle = new Ion (0,NUM_CELLS-1,0);
    weighing (particle, weights);
    ASSERT_EQ (weights [0], 1);
    ASSERT_EQ (weights [1], 0);
}

TEST (weighing_test, Middle){
    double *weights = new double [2];
    Ion *particle = new Ion (0,1.5,1);
    weighing (particle, weights);

    ASSERT_EQ (weights [0], .5);
    ASSERT_EQ (weights [1], .5);
}
