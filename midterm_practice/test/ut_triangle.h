#pragma once

#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/triangle.h"
#include "../src/twoDimensionVector.h"
#include "math.h"

class TriangleTest: public ::testing::Test{
protected:
    ~TriangleTest(){}

    TriangleTest(){}

    void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            TwoDimensionVector vec1(3.0, 4.0);
            TwoDimensionVector vec2(5.0, 12.0);
            t = new Triangle(vec1, vec2);
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete t;
        }

    // Class members declared here can be used by all tests in the test suite
    Shape* t;
};

TEST_F(TriangleTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*t)==typeid(Triangle));
}

TEST_F(TriangleTest, AreaIsCorrect){
    TwoDimensionVector vec1(3.0, 4.0);
    TwoDimensionVector vec2(5.0, 12.0);

    double vec3length = vec1.subtract(vec2).length();
    double s = (vec1.length()+vec2.length()+vec3length)/2.0;
    double helon_expected = sqrt(s*(s-vec1.length())*(s-vec2.length())*(s-vec3length));
    // Expected
    ASSERT_EQ(t->area(), helon_expected);
}

TEST_F(TriangleTest, PerimeterIsCorrect){
    TwoDimensionVector vec1(3.0, 4.0);
    TwoDimensionVector vec2(5.0, 12.0);

    // Expected
    ASSERT_EQ(t->perimeter(), vec1.length()+vec2.length()+vec1.subtract(vec2).length());
}

TEST_F(TriangleTest, InfoIsCorrect){
    // Expected
    ASSERT_EQ(t->info(), "Triangle (3.00, 4.00) (5.00, 12.00)");
}

TEST_F(TriangleTest, CreationThrowsParallelVectors){
    // Expected
    try{
        TwoDimensionVector vec1(3.0, 4.0);
        TwoDimensionVector vec2(6.0, 8.0);
        Triangle t1(vec1, vec2);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Vectors can't be parallel.");
    }
}

TEST_F(TriangleTest, AddShapeThrowsException){
    // Expected
    try{
        TwoDimensionVector vec1(3.0, 4.0);
        TwoDimensionVector vec2(5.0, 8.0);
        Triangle t1(vec1, vec2);
        t->addShape(&t1);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Basic Shape don't have addShape().");
    }
}

TEST_F(TriangleTest, DeleteShapeThrowsException){
    // Expected
    try{
        TwoDimensionVector vec1(3.0, 4.0);
        TwoDimensionVector vec2(5.0, 8.0);
        Triangle t1(vec1, vec2);
        t->deleteShape(&t1);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Basic Shape don't have deleteShape().");
    }
}