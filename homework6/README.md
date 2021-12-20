# Pattern Oriented Software Design 2021 Fall Assignment

## Assignment List
- [Assignment 1:](Assignment1.md) Due 10/06
- [Assignment 2:](Assignment2.md) Due 10/18
- [Assignment 3:](Assignment3.md) Due 11/04
- [Assignment 4:](Assignment4.md) Due 12/01
- [Assignment 5:](Assignment5.md) Due 12/15
- [Assignment 6:](Assignment6.md) Due 12/27

## Assignment 6

__Deadline__: 12/27 23:59.

The folders `src/` and `test/` in this repo contain the template code of the
assignment, which is just the skeleton. 
You need to finish the implementation by yourself. 

For this assignment, you are asked to implement singleton pattern on `Builder` 
and implement console `I/O` subsystem.

Please add to the skeleton code so that it meets the specifications below.
- The specs of `Shape`, `Circle`, `Rectangle`, `Triangle` and 
  `TwoDimensionalVector` is extended from the assignment 4.
---
- The specs of `Iterator` is extended from the assignment 3, make sure it works in this assignment.
---
- Most of the specs of `ShapeBuilder`, `ShapeParser`, `Scanner` and 
`ShapeInfoVisitor` are extended from the assignment 5, make sure all of them work in this assignment.
- In this assignment, `ShapeBuilder` should implement singleton pattern and can
get the shape instance it constructs via `getInstance()`. Reset `ShapeBuilder`'s state via `reset()`.
- remember to reset builder after `getShape()` in `ShapeParser`.
---
- For `I/O` system, add class `InstructionHandler` which should show the instructions
to user, execute the instruction chosen by user, and catch any exception during
build process.
- You should follow [io instructions](io_instruction.md) to complete the `I/O` system.
- You can skip unit testing for this subsystem.
---
- TA will only check `ShapeBuilder` and `I/O`, but you still need to ensure the whole program works.

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
- `I/O` system will be tested manually by TA.

### Grading Rubrics
1. Unit tests written by yourself: 30%.
2. Unit tests written by TA: 30%.
3. Main I/O subsystem: 40%

### File Structure

  ```bash
  .
├── README.md
├── io_instruction.md
├── makefile
├── src
│   ├── builder
│   │   ├── scanner.h
│   │   ├── shape_builder.h
│   │   └── shape_parser.h
│   ├── circle.h
│   ├── compound_shape.h
│   ├── input_handler.cpp
│   ├── input_handler.h
│   ├── iterator
│   │   ├── compound_iterator.h
│   │   ├── iterator.h
│   │   └── null_iterator.h
│   ├── main.cpp
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
    ├── data
    │   ├── circle.txt
    │   ├── complex_compound.txt
    │   ├── empty_compound.txt
    │   ├── rectangle.txt
    │   ├── simple_compound.txt
    │   └── triangle.txt
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
