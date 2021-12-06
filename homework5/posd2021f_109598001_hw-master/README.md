# Pattern Oriented Software Design 2021 Fall Assignment

## Assignment List
- [Assignment 1:](Assignment1.md) Due 10/06
- [Assignment 2:](Assignment2.md) Due 10/18
- [Assignment 3:](Assignment3.md) Due 11/04
- [Assignment 4:](Assignment4.md) Due 12/01
- [Assignment 5:](Assignment5.md) Due 12/15

## Assignment 5

__Deadline__: 12/15 23:59.

The folders `src/` and `test/` in this repo contain the template code of the
assignment, which is just the skeleton. 
You need to finish the implementation by yourself. 

For this assignment, you are asked to implement `Builder` pattern and practice 
how to read text from a file in C++.

Please add to the skeleton code so that it meets the specifications below.
- The specs of `Shape`, `Circle`, `Rectangle`, `Triangle` and 
  `TwoDimensionalVector` is extended from the assignment 4.
---
- The specs of `Iterator` is extended from the assignment 3, you should keep all
iterator functionality work in this assignment.
---
- The specs of `Visitor` is extended from the assignment 4, you should keep all
iterator functionality work in this assignment.
- When `ShapeInfoVisitor` visits `CompoundShape`, visitor wraps children's info 
  with `CompoundShape {\n...}\n` and adds indent by their depth in the compound 
  tree.
---
- class `ShapeBuilder`, which builds `Shape` object with arguments and pushes 
  the object into a result stack.
  - when building `Circle`, builder needs **radius**.
  - when building `Rectangle`, builder needs **length** and **width**.
  - when building `Triangle`, builder generates a 2D vector by **x1**, **y1** 
    and the other 2D vector by **x2**, **y2**, and then uses the two vectors to 
    build `Triangle`.
  - when building `CompoundShape`, builder pushes a new `CompoundShape` into the 
    result stack in the beginning, and adds all the `Shape` objects pushed after
    the `CompoundShape` into the `CompoundShape` in the end.
  - when `getResult()` is called, builder returns the top of the result stack.
  - you don't need to verify if arguments are valid in `ShapeBuilder`.
- class `Scanner`, which scans through the input and extracts doubles and tokens
  in token list defined by TA.
  - token list: {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", 
    "[", "]", "{", "}", ","}
  - it points to next token in function `next`, and it will throw exception if 
    it already points to the end position of the input.
  - it points to next token in function `nextDouble`, and it will throw 
    exception if it already points to the end position of the input.
  - it returns the result which checks if it points to the end position of the 
    input after skipping white space in function `isDone`, where white space 
    includes " ", "\n" and "\t".
  - you should ignore the token which is illegal.
    ```
    // Example
    std::string input = "I Circle eee ,tt{t3.14159a";
    Scanner scanner(input);
    std::string first = scanner.next();      // `first` is "Circle"
    std::string second = scanner.next();     // `second` is ","
    double third = scanner.nextDouble();     // `third` is 3.14159
    ```
- class `ShapeParser`, which accepts a file path, that is a relative path of 
  `makefile`, and uses scanner as well as builder to parse a `Shape` object in 
  the file.
  - it creates scanner and builder in the constructor.
  - it handles the logic of parsing in function `parse`.
---
- TA will only check `ShapeBuilder`, `ShapeParser`, `Scanner` and 
  `ShapeInfoVisitor`, but you still need to keep all legacy system work.

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
CompoundShape {\n
  Circle (12.35)\n
  CompoundShape {\n
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
- The folder `test/data/` is not necessary, but you can take it for reference.

### Grading Rubrics
1. Unit tests written by yourself: 50%.
2. Unit tests written by TA: 50%.

### File Structure

  ```bash
  .
  ├── makefile
  ├── src
  │   ├── builder
  │   │   ├── scanner.h
  │   │   ├── shape_builder.h
  │   │   └── shape_parser.h
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
      ├── builder
      │   ├── ut_scanner.h
      │   ├── ut_shape_builder.h
      │   └── ut_shape_parser.h
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
- [std::stack](https://www.cplusplus.com/reference/stack/stack/)

## Course Link
Course Link: https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2021f

## Environment Setting
Tutorial: https://ssl-gitlab.csie.ntut.edu.tw/course/environment_setting.git
