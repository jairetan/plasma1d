#include "adjacent_coods_test.h"

TEST (adjacent_points_test, LeftBound){
    int *points = new int [2];
    Ion *particle = new Ion (0,0,0);
    adjacent_points (particle, points);

    ASSERT_EQ (points [0], 0);
    ASSERT_EQ (points [1], 1);
}

TEST (adjacent_points_test, RightBound){
    int *points = new int [2];
    Ion *particle = new Ion (0,NUM_CELLS-1,0);
    adjacent_points (particle, points);

    ASSERT_EQ (points [0], NUM_CELLS-1);
    ASSERT_EQ (points [1], 0);
}
