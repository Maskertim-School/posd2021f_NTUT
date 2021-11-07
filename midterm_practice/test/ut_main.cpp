#include <gtest/gtest.h>
#include "ut_circle.h"
#include "ut_rectangle.h"
#include "ut_twoDimensionVector.h"
#include "ut_triangle.h"
#include "ut_null_iterator.h"
#include "ut_compound_iterator.h"
#include "ut_compound_shape.h"
#include "ut_select_shape_visitor.h"
#include "ut_utility.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}