#include <gtest/gtest.h>
// Composite pattern
#include "ut_circle.h"
#include "ut_rectangle.h"
#include "ut_two_dimensional_vector.h"
#include "ut_triangle.h"
#include "ut_compound_shape.h"
// Iterator pattern
#include "iterator/ut_null_iterator.h"
#include "iterator/ut_compound_iterator.h"
// Visitor pattern
#include "visitor/ut_shape_info_visitor.h"
// Builder pattern
#include "./builder/ut_shape_builder.h"
#include "./builder/ut_scanner.h"
#include "./builder/ut_shape_parser.h"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}