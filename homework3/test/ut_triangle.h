#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include <cmath>

/* Follow the Homework 1 */
TEST(CaseTriangle, Creation){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    Triangle triangle(t1, t2);
    ASSERT_EQ(typeid(triangle), typeid(Triangle));
}

TEST(CaseTriangle, Area){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, 4.0);
    Triangle triangle(t1, t2);
    double len3 = t1.subtract(t2).length();
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
    double len3 = t1.subtract(t2).length();
    double expected = len1+len2+len3;

    ASSERT_NEAR(triangle.perimeter(), expected, 0.001);
}

TEST(CaseTriangle, TwoVectorsParallelException){
    TwoDimensionalVector t1(2.0, 4.0);
    TwoDimensionalVector t2(1.0, 2.0);
    try{
        Triangle triangle(t1, t2);
    }catch(std::string msg){
        ASSERT_EQ("The parallel of two vectors don't form a triangle.", msg);
    }
}

TEST(CaseTriangle, Info){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, -4.0);
    Triangle triangle(t1, t2);
    ASSERT_EQ(triangle.info(), "Triangle ([5.00,12.00] [3.00,-4.00])");
}

/* other operations */
TEST(CaseTriangle, AddShapeException){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, -4.0);
    TwoDimensionalVector t3(5.0, -12.0);
    TwoDimensionalVector t4(3.0, 4.0);
    Shape* triangle = new Triangle(t1, t2);
    Shape* triangle2 = new Triangle(t1, t2);
    try{
        triangle->addShape(triangle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("Uncomposite shape don't have method of addShape.", msg);
    }
}

TEST(CaseTriangle, DeleteShapeException){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, -4.0);
    TwoDimensionalVector t3(5.0, -12.0);
    TwoDimensionalVector t4(3.0, 4.0);
    Shape* triangle = new Triangle(t1, t2);
    Shape* triangle2 = new Triangle(t1, t2);
    try{
        triangle->deleteShape(triangle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("Uncomposite shape don't have method of deleteShape.", msg);
    }
}

TEST(CaseTriangle, IsDoneOfIteratorShouldBeTrue){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, -4.0);
    Shape* triangle = new Triangle(t1, t2);
    Iterator* nit = triangle->createIterator();
    
    ASSERT_TRUE(nit->isDone());
}

TEST(CaseTriangle, CurrentItemOfIteratorShouldBeThrowException){
    TwoDimensionalVector t1(5.0, 12.0);
    TwoDimensionalVector t2(3.0, -4.0);
    Shape* triangle = new Triangle(t1, t2);
    Iterator* nit = triangle->createIterator();
    
    try{
        nit->currentItem();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The currentItem method of Null Iterator is not allowed.", msg);
    }
}