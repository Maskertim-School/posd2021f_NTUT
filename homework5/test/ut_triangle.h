#pragma once

#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include "math.h"

class TriangleTest: public ::testing::Test{
protected:
    ~TriangleTest(){}

    TriangleTest(){}

    void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            TwoDimensionalVector vec1(3.0, 4.0);
            TwoDimensionalVector vec2(5.0, 12.0);
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

TEST_F(TriangleTest, CreateIteratorNoException){
    Iterator* it = t->createIterator();
    // Expected
    ASSERT_TRUE(typeid(*it)==typeid(NullIterator));

    delete it;
}

TEST_F(TriangleTest, AreaIsCorrect){
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(5.0, 12.0);

    double vec3length = vec1.subtract(vec2).length();
    double s = (vec1.length()+vec2.length()+vec3length)/2.0;
    double helon_expected = sqrt(s*(s-vec1.length())*(s-vec2.length())*(s-vec3length));
    // Expected
    ASSERT_EQ(t->area(), helon_expected);
}

TEST_F(TriangleTest, PerimeterIsCorrect){
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(5.0, 12.0);

    // Expected
    ASSERT_EQ(t->perimeter(), vec1.length()+vec2.length()+vec1.subtract(vec2).length());
}

TEST_F(TriangleTest, InfoIsCorrect){
    // Expected
    ASSERT_EQ(t->info(), "Triangle ([3.00,4.00] [5.00,12.00])");
}

TEST_F(TriangleTest, InfoRoundingUpIsCorrect){
    TwoDimensionalVector vec1(3.256, 4.103);
    TwoDimensionalVector vec2(5.222, 12.437);
    Shape* t = new Triangle(vec1, vec2);
    // Expected
    ASSERT_EQ(t->info(), "Triangle ([3.26,4.10] [5.22,12.44])");
}

TEST_F(TriangleTest, CreationThrowsParallelVectors){
    // Expected
    try{
        TwoDimensionalVector vec1(3.0, 4.0);
        TwoDimensionalVector vec2(6.0, 8.0);
        Triangle t1(vec1, vec2);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Vectors can't be parallel.");
    }
}

TEST_F(TriangleTest, AddShapeThrowsException){
    // Expected
    try{
        TwoDimensionalVector vec1(3.0, 4.0);
        TwoDimensionalVector vec2(5.0, 8.0);
        Triangle t1(vec1, vec2);
        t->addShape(&t1);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "can't add shape");
    }
}

TEST_F(TriangleTest, DeleteShapeThrowsException){
    // Expected
    try{
        TwoDimensionalVector vec1(3.0, 4.0);
        TwoDimensionalVector vec2(5.0, 8.0);
        Triangle t1(vec1, vec2);
        t->deleteShape(&t1);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "can't delete shape");
    }
}

TEST_F(TriangleTest, Accept){
    ShapeInfoVisitor visitor;
    t->accept(&visitor);
    //Expected
    ASSERT_EQ(visitor.getResult(), "Triangle ([3.00,4.00] [5.00,12.00])\n");
}