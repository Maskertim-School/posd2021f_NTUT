#pragma once

#include <gtest/gtest.h>
#include "../src/circle.h"
#include "../src/shape.h"
#include <cmath>

class CircleTest: public ::testing::Test {
    protected:
        CircleTest(){}
        ~CircleTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            c = new Circle(10.0);
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete c;
        }

    // Class members declared here can be used by all tests in the test suite
    Shape* c;
};

TEST_F(CircleTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*c)==typeid(Circle));
}

TEST_F(CircleTest, AreaIsCorrect){
    // Expected
    ASSERT_EQ(c->area(), 10.0*10.0*M_PI);
}

TEST_F(CircleTest, PerimeterIsCorrect){
    // Expected
    ASSERT_EQ(c->perimeter(), 10.0*2*M_PI);
}

TEST_F(CircleTest, InfoIsCorrect){
    // Expected
    std::string expected = "Circle (10.00)";
    ASSERT_EQ(c->info(), expected);
}

TEST_F(CircleTest, CreationThrowsNegativeRadius){
    // Expected
    try{
        Circle c(-5.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Radius can't be negative and zero.");
    }
}

TEST_F(CircleTest, CreationThrowsZeroRadius){
    // Expected
    try{
        Circle c(0.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Radius can't be negative and zero.");
    }
}

TEST_F(CircleTest, AddShapeThrowsException){
    // Expected
    try{
        c->addShape(new Circle(2.0));
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Basic Shape don't have addShape().");
    }
}

TEST_F(CircleTest, DeleteShapeThrowsException){
    // Expected
    try{
        c->deleteShape(new Circle(2.0));
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Basic Shape don't have deleteShape().");
    }
}