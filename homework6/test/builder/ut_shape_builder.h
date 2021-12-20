#include "../../src/builder/shape_builder.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/triangle.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/compound_shape.h"
#include <math.h>

TEST(CaseBuilder, Creation){
    // ShapeBuilder* shape_builder = new ShapeBuilder();
    ShapeBuilder* shape_builder = ShapeBuilder::getInstance();
    // Expected
    ASSERT_TRUE(typeid(*shape_builder)==typeid(ShapeBuilder));

    // delete shape_builder;
    shape_builder->reset();
}

TEST(CaseBuilder, BuildCircle){
    // ShapeBuilder* sb = new ShapeBuilder();
    ShapeBuilder* sb = ShapeBuilder::getInstance();
    sb->buildCircle(5.0);

    // Expected
    ASSERT_EQ(sb->getShape()->area(), 5.0*5.0*M_PI);

    sb->reset();
}

TEST(CaseBuilder, BuildRectangle){
    // ShapeBuilder* sb = new ShapeBuilder();
    ShapeBuilder* sb = ShapeBuilder::getInstance();
    sb->buildRectangle(3.00, 5.0);

    // Expected
    ASSERT_EQ(sb->getShape()->area(), 3.00*5.0);

    sb->reset();
}

TEST(CaseBuilder, BuildTriangle){
    // ShapeBuilder* sb = new ShapeBuilder();
    ShapeBuilder* sb = ShapeBuilder::getInstance();
    sb->buildTriangle(3.0, 4.0, 2.0, 5.0);

    // Expected
    TwoDimensionalVector t1(3.0, 4.0);
    TwoDimensionalVector t2(2.0, 5.0);
    Triangle answer(t1, t2);

    ASSERT_EQ(sb->getShape()->area(), answer.area());

    sb->reset();
}

TEST(CaseBuilder, BuildCompoundBegin){
    // ShapeBuilder* sb = new ShapeBuilder();
    ShapeBuilder* sb = ShapeBuilder::getInstance();
    sb->buildCompoundBegin();

    // Expected
    ASSERT_TRUE(typeid(*(sb->getShape())) == typeid(CompoundShape));

    sb->reset();
}

TEST(CaseBuilder, BuildCompoundEnd){
    // ShapeBuilder* sb = new ShapeBuilder();
    ShapeBuilder* sb = ShapeBuilder::getInstance();
    sb->buildCompoundBegin();
    sb->buildCircle(1.0);
    sb->buildRectangle(1.0, 2.0);
    sb->buildCompoundEnd();

    // Expected
    Circle c(1.0);
    Rectangle r(1.0, 2.0);
    ASSERT_EQ(sb->getShape()->area(), (c.area()+r.area()));

    sb->reset();
}

TEST(CaseBuilder, BuildCompoundEndWithComplex){
    // ShapeBuilder* sb = new ShapeBuilder();
    ShapeBuilder* sb = ShapeBuilder::getInstance();
    sb->buildCompoundBegin();
    sb->buildCompoundBegin();
    sb->buildCircle(1.0);
    sb->buildCircle(1.0);
    sb->buildCompoundEnd();
    sb->buildRectangle(1.0, 2.0);
    sb->buildCompoundEnd();

    // Expected
    Circle c(1.0);
    Rectangle r(1.0, 2.0);
    ASSERT_EQ(sb->getShape()->area(), (2*c.area()+r.area()));

    sb->reset();
}