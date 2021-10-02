#include "../src/two_dimensional_vector.h"
#include <cmath>

TEST(CaseTwoDimensionVector, Length){
    TwoDimensionalVector t1(5.0, 5.0);
    double expected = sqrt(pow(5.0, 2)+pow(5.0, 2));
    ASSERT_NEAR(t1.length(), expected, 0.001);
}

TEST(CaseTwoDimensionVector, Dot){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    ASSERT_NEAR(t1.dot(t2), 5.0*3.0+12.0*4.0, 0.001);
}

TEST(CaseTwoDimensionVector, Cross){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    ASSERT_NEAR(t1.cross(t2), 5.0*4.0-12.0*3.0, 0.001);
}

TEST(CaseTwoDimensionVector, Substract){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(-3.0, -4.0);
    TwoDimensionalVector result = t1.substract(t2);
    ASSERT_NEAR(result.x(), 8.0, 0.001);
    ASSERT_NEAR(result.y(), 16.0, 0.001);
}

TEST(CaseTwoDimensionVector, Info){
    TwoDimensionalVector t1(-3.0, -4.0);
    ASSERT_EQ(t1.info(), "[-3.00,-4.00]");
}