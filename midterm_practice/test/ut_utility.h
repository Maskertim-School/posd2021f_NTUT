#include "../src/utility.h"
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/compound_shape.h"

TEST(UtilityTest, DecimalPoint){
    double mock = 10.0;
    // Expected
    ASSERT_EQ(decimalpoint(mock, 2), "10.00");
}

TEST(UtilityTest, SelectFirstShapeWithBaseShape){
    Shape* c= new Circle(3.0);
    // Expected
    ASSERT_EQ(SelectFirstShape(c, [](Shape* s){
        return s->area() > 10.0 && s->area() < 30.0;
    }), c);
}

TEST(UtilityTest, SelectFirstShapeWithCompoundShapeCompatible){
    Shape* c= new Circle(3.0);
    Shape* c2 = new Circle(10.0);

    Shape* cs = new CompoundShape();
    cs->addShape(c2);
    cs->addShape(c);
    // Expected
    ASSERT_EQ(SelectFirstShape(cs, [](Shape* s){
        return s->area() > 10.0 && s->area() < 30.0;
    }), c);
}

TEST(UtilityTest, SelectFirstShapeWithCompoundShapeNonCompatible){
    Shape* c= new Circle(7.0);
    Shape* c2 = new Circle(10.0);

    Shape* cs = new CompoundShape();
    cs->addShape(c2);
    cs->addShape(c);
    // Expected
    ASSERT_EQ(SelectFirstShape(cs, [](Shape* s){
        return s->area() > 10.0 && s->area() < 30.0;
    }), nullptr);
}