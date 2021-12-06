# Pattern Oriented Software Design 2021 Fall Assignment

## Assignment 4

__Deadline__: 12/01 23:59.

The folders `src/` and `test/` in this repo contain the template code of the
assignment, which is just the skeleton. 
You need to finish the implementation by yourself. 

For this assignment, you are asked to implement `Visitor` pattern.

Please add to the skeleton code so that it meets the specifications below.
- The specs of `Shape`, `Circle`, `Rectangle`, `Triangle` and 
  `TwoDimensionalVector` is extended from the assignment 3.
- abstract class `Shape`, which has a pure virtual function `accept` and `info`.
- function `accept` takes a visitor as parameter and visit the shape.
- function `info` returns a string that describes the shape.
  - `Circle` returns "Circle (${radius})".
  - `Rectangle` returns "Rectangle (${length}, ${width})".
  - `Triangle` returns "Triangle (${vec1.info()}, ${vec2.info()})".
  - `CompoundShape` returns "CompoundShape".
- class `CompoundShape`, which deletes first matching Shape object in function 
  `deleteShape`, and it will traverse all its descendants.
---
- The specs of `Iterator` is extended from the assignment 3, you should keep all
iterator functionality work in this assignment.
---
- Abstract class `ShapeVisitor` defines four pure virtual functions `visitCircle`,
  `visitRectangle`, `visitTriangle` and `visitCompoundShape`.
- Class `ShapeInfoVisitor` is derived from `ShapeVisitor`, implements all pure
  functions defined in `ShapeVisitor`.
- Class `ShapeInfoVisitor` generates shape info in following rule:
  - when visit `Circle`, visitor generates "Circle (${radius})\n".
  - when visit `Rectangle`, visitor generates "Rectangle (${length}, ${width})\n".
  - when visit `Triangle`, visitor generates "Triangle (${vec1.info()}, ${vec2.info()})
    \n".
  - when visit `CompoundShape`, visitor wraps children's info with `CompoundShape{\n...}\n`
    and adds indent by their depth in the compound tree.
---
- TA will only check `ShapeVisitor`, `accept()`, `info()`, `deleteShape()`, but you still needs to keep all legacy system work.


#### Example:

``` c++
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(1.1));
  cs1->addShape(new Rectangle(3.14 ,4));

  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(new Circle(12.34567))
  cs2->addShape(cs1);

  ShapeInfoVisitor visitor;
  cs2.accept(&visitor);

```

result of `visitor.getResult()`(don't print '\n', it just remind you there has a \n)
```
CompoundShape{\n
  Circle (12.35)\n
  CompoundShape{\n
    Circle (1.10)\n
    Rectangle (3.14 4.00)\n
  }\n
}\n
```

#### Notes:
- If your code fails to compile on the Jenkins server, you'll get **NO POINT** 
  for the assignment.
- Your program should be able to handle unexpected input data, that is, you
  should do error handling if necessary.
- You should make your unit test fail if the program that should throw an 
  exception runs without throwing one.
- When writing unit tests, you should take as many situations as possible into
  consideration.
- Discussion is encouraged but the pushed code must be your own.
- Any submission after deadline will not be graded.
- You don't need to delete the tests written before.
- Remember to **RELEASE THE SPACE** you allocate after using it.

### Grading Rubrics
1. Unit tests written by yourself: 50%.
2. Unit tests written by TA: 50%.

### File Structure

  ```bash
  .
  ├── makefile
  ├── src
  │   ├── circle.h
  │   ├── compound_shape.h
  │   ├── iterator
  │   │   ├── compound_iterator.h
  │   │   ├── iterator.h
  │   │   └── null_iterator.h
  │   ├── rectangle.h
  │   ├── shape.h
  │   ├── triangle.h
  │   ├── two_dimensional_vector.h
  │   └── visitor
  │       ├── shape_info_visitor.h
  │       └── shape_visitor.h
  └── test
      ├── iterator
      │   ├── ut_compound_iterator.h
      │   └── ut_null_iterator.h
      ├── ut_circle.h
      ├── ut_compound_shape.h
      ├── ut_main.cpp
      ├── ut_rectangle.h
      ├── ut_triangle.h
      ├── ut_two_dimensional_vector.h
      └── visitor
          └── ut_shape_info_visitor.h
  ```

## References
- [C++.com](http://www.cplusplus.com/reference/)

## Course Link
Course Link: https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2021f

## Environment Setting
Tutorial: https://ssl-gitlab.csie.ntut.edu.tw/course/environment_setting.git