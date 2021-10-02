#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include <cmath>

TEST(CaseTriangle, Area){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    Triangle triangle(t1, t2);
    double len3 = t1.substract(t2).length();
    double s = (t1.length()+t2.length()+len3)/2.0;
    double expected = sqrt(s*(s-t1.length())*(s-t2.length())*(s-len3));
    ASSERT_NEAR(triangle.area(), expected, 0.001);
}

TEST(CaseTriangle, Perimeter){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    Triangle triangle(t1, t2);
    double len1 = t1.length();
    double len2 = t2.length();
    double len3 = t1.substract(t2).length();
    double expected = len1+len2+len3;

    ASSERT_NEAR(triangle.perimeter(), expected, 0.001);
}

TEST(CaseTriangle, ParallelException){
    TwoDimensionalVector t1(2.0, 4.0);
    TwoDimensionalVector t2(1.0, 2.0);
    try{
        Triangle triangle(t1, t2);
    }catch(std::string msg){
        ASSERT_EQ("This is not a triangle.", msg);
    }
}

TEST(CaseTriangle, Info){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, -4.0);
    Triangle triangle(t1, t2);
    ASSERT_EQ(triangle.info(), "Triangle ([5.00,12.00] [3.00,-4.00])");
}