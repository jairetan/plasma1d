#include "wrap_around_test.h"

TEST (wrap_around_test, WrapRight)
{
    ASSERT_EQ (1, wrap_around (101, 100));
}

TEST (wrap_around_test, WrapLeft)
{
    ASSERT_EQ (99, wrap_around (-1, 100));
}

TEST (wrap_around_test, WrapNothing)
{
    ASSERT_EQ (50, wrap_around (50, 100));
}




