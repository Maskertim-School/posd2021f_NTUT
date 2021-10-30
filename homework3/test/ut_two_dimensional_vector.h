#include "../src/two_dimensional_vector.h"
#include <cmath>

TEST(CaseTwoDimensionVector, XIsCorrect){
    TwoDimensionalVector t1(5.0, 5.0);
    ASSERT_NEAR(t1.x(), 5.0, 0.001);
}

TEST(CaseTwoDimensionVector, YIsCorrect){
    TwoDimensionalVector t1(5.0, 3.0);
    ASSERT_NEAR(t1.y(), 3.0, 0.001);
}

TEST(CaseTwoDimensionVector, Length){
    TwoDimensionalVector t1(5.0, 5.0);
    double expected = sqrt(pow(5.0, 2)+pow(5.0, 2));
    ASSERT_NEAR(t1.length(), expected, 0.001);
}

TEST(CaseTwoDimensionVector, DotProductOfTwoOrthogonalVectorsShouldBeZero){
    TwoDimensionalVector t1(5.0, 0.0);
    TwoDimensionalVector t2(0.0, 12.0);
    ASSERT_NEAR(t1.dot(t2), 5.0*0.0+0.0*12.0, 0.001);
}

TEST(CaseTwoDimensionVector, DotProductOfTwoVectorsWithAcuteAngleShouldBePositive){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    ASSERT_NEAR(t1.dot(t2), 5.0*3.0+12.0*4.0, 0.001);
}

TEST(CaseTwoDimensionVector, DotProductOfTwoVectorsWithObtuseAngleShouldBeNegative){
    TwoDimensionalVector t1(5.0, -12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    ASSERT_NEAR(t1.dot(t2), 5.0*3.0+(-12.0)*4.0, 0.001);
}

TEST(CaseTwoDimensionVector, CrossProductOfTwoParallelVectorsShouldBeZero){
    TwoDimensionalVector t1(6.0, 8.0);
    TwoDimensionalVector t2(3.0, 4.0);
    ASSERT_NEAR(t1.cross(t2), 6.0*4.0-8.0*3.0, 0.001);
}

TEST(CaseTwoDimensionVector, CrossProductOfTwoVectorsWithCounterclockwiseShouldBePositive){
    TwoDimensionalVector t1(3.0, 4.0);
    TwoDimensionalVector t2(5.0, 12.0);
    ASSERT_NEAR(t1.cross(t2), 12.0*3.0-5.0*4.0, 0.001);
}

TEST(CaseTwoDimensionVector, CrossProductOfTwoVectorsWithClockwiseShouldBeNegative){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    ASSERT_NEAR(t1.cross(t2), 5.0*4.0-12.0*3.0, 0.001);
}


TEST(CaseTwoDimensionVector, SubtractReturnsCorrectVector){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(-3.0, -4.0);
    TwoDimensionalVector result = t1.subtract(t2);
    ASSERT_NEAR(result.x(), 8.0, 0.001);
    ASSERT_NEAR(result.y(), 16.0, 0.001);
}

TEST(CaseTwoDimensionVector, Info){
    TwoDimensionalVector t1(-3.0, -4.0);
    ASSERT_EQ(t1.info(), "[-3.00,-4.00]");
}