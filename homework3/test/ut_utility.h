#include "../src/utility.h"
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/compound_shape.h"

TEST(CaseUtility, SelectShapeHaveFirstForArea){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    Shape* result = selectShape(cs, [](Shape* shape) {
        return shape->area() >= 40.0 && shape->area() <= 50.0;
    });

    ASSERT_EQ(typeid(*result).name(), typeid(*cs2).name());

    delete cs;
}

TEST(CaseUtility, SelectShapeHaveFirstForPerimeter){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    Shape* result = selectShape(cs, [](Shape* shape) {
        return shape->perimeter() >= 30.0 && shape->perimeter() <= 40.0;
    });

    ASSERT_EQ(typeid(*result).name(), typeid(*circle).name());

    delete cs;
}

TEST(CaseUtility, SelectShapeNothingForArea){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    Shape* result = selectShape(cs, [](Shape* shape) {
        return shape->area() <= 10.0;
    });

    ASSERT_TRUE(result == nullptr);

    delete cs;
}

TEST(CaseUtility, SelectShapeNothingForPerimeter){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    Shape* result = selectShape(cs, [](Shape* shape) {
        return shape->perimeter() <= 10.0;
    });

    ASSERT_TRUE(result == nullptr);

    delete cs;
}

TEST(CaseUtility, SelectShapeByType){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    Shape* result = selectShape(cs, [](Shape* shape) {
        return typeid(*shape)==typeid(Circle);
    });

    ASSERT_EQ(typeid(*result).name(), typeid(*circle).name());

    delete cs;
}