# Pattern Oriented Software Design 2021 Fall Assignment

## Assignment 1
#### Deadline: 10/06 Wed 23:59.

The packages `src/` and `test/` in this repo are the template code of the 
assignment.
The template is just the skeleton.
You should finish implementation by yourself.

For this assignment, you'll implement `Shape` objects, practice to use TDD, and
learn how to handle exception.

Please complete the given code to satisfy all the specs of the `Shape` problem 
and the following conditions.

- abstract class `Shape`, which has immutable `area`, `perimeter` and `info`.
- class `Rectangle`, `Triangle` and `Circle`, where all of them are `Shape`, 
that is, they should implement all methods of `Shape`.
- class `Rectangle`, which is created by positive double length and width.
- class `Triangle`, which is created by two non-parallel two dimensional 
vectors.
- class `Circle`, which is created by positive double radius.
- the format of `info` should contain **type** and **information** of a `Shape` 
object. The example is below.
  ```
  // case `Rectangle with length 3.14, width 4`: 
  Rectangle (3.14 4.00)
  
  // case `Triangle with vector1 (3, 12.433) and vector2 (17.56789, -4)`: 
  Triangle ([3.00,12.43] [17.57,-4.00])

  // case `Circle with radius 1.1`:
  Circle (1.10)
  ```
---
- class `TwoDimensionalVector`, which has immutable double `x`, `y`, `length` 
and `info`, and it can `subtract` and calculate `dot product` and 
`cross product` with another TwoDimensionalVector. The start point of each 
vector is (0, 0), and the end point of each vector is (`x`, `y`). The example of 
`info` is below.
  ```
  // case `(3, 12.433)`:
  [3.00,12.43]
  ```
- file `makefile`, which generates binary file named `ut_all` under the package 
`bin/` for all test files.

#### Notes:
- If your code fails to compile on jenkins server, you'll get **NO POINT** for
the assignment.
- Your program should be able to handle unexpected input data, that is, you
should do error handling if necessary.
- You should make your unit test fail if the program that should throw error
runs without any problem.
- When writing unit tests, you should take as many situations as possible into
consideration.
- Discussion is encouraged but code must be your own.
- If the type of returned value is `double`, you should assert the value to 
accuracy `%.3f`.
- You should round off `double` value to `%.2f` when number is showed in `info`.

#### Hints:
- You can use `M_PI` in \<cmath> for calculation of `π`.

### Grading Rubrics
1. Unit tests written by yourself: 50%. (You have to write tests covering all 
conditions, and make them pass.)
2. Unit tests written by TA: 50%.

### File Structure
```
.
├── bin
│   └── ut_all
├── src
│   ├── circle.h
│   ├── rectangle.h
│   ├── shape.h
│   ├── triangle.h
│   └── two_dimensional_vector.h
├── test
│   ├── ut_circle.h
│   ├── ut_main.cpp
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   └── ut_two_dimensional_vector.h
└── makefile
```


## References
- [C++.com](http://www.cplusplus.com/reference/)
- [C++ Exception Handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)
- [Makefile Tutorial](https://ssl-gitlab.csie.ntut.edu.tw/course/makefile_tutorial)
- [Vector Introduction](https://mathinsight.org/cross_product_formula)
- [Dot Product Formula](https://mathinsight.org/dot_product_formula_components)
- [Cross Product Formula](https://mathinsight.org/cross_product_formula)

## Course Link
Course Link: https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2021f

## Environment Setting
Tutorial: https://ssl-gitlab.csie.ntut.edu.tw/course/environment_setting.git