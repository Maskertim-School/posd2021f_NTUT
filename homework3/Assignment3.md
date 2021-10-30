# Pattern Oriented Software Design 2021 Fall Assignment

## Assignment 3

__Deadline__: 11/04 23:59.

The folders `src/` and `test/` in this repo contain the template code of the
assignment, which is just the skeleton. 
You need to finish the implementation by yourself. 

For this assignment, you are asked to implement `Iterator` pattern, change data 
structure of `Shape` container in `CompoundShape` from array to `std::list` and 
practice to use template in C++.

Please add to the skeleton code so that it meets the specifications below.
- The specs of `Shape`, `Circle`, `Rectangle`, `Triangle` and 
  `TwoDimensionalVector` is extended from the assignment 1.
- abstract class `Shape`, which adds a pure virtual function `createIterator` 
  and virtual functions `addShape` and `deleteShape`.
  - It defines throwing an exception as default behavior of function `addShape`
    and `deleteShape`. 
- class `Circle`, `Rectangle` and `Triangle`, all of which implement the
  virtual function `createIterator` derived from `Shape`, and they should return 
  a iterator which doesn't point to any address in function `createIterator`.
- class `CompoundShape`, which is derived from `Shape`, implements all functions 
  in `Shape`, and uses `CompoundIterator` as its iterator.
---
- abstract class `Iterator`, which defines four pure virtual functions `first`, 
  `currentItem`, `next` and `isDone`.
- class `NullIterator` and `CompoundIterator`, both of which are derived from
  `Iterator`, that is, they should implement all pure functions defined in 
  `Iterator`.
- class `NullIterator`, which doesn't point to any address, so it will throw 
  exception when its functions: `first`, `currentItem` and `next` are called, 
  and its function `isDone` is always true.
- class `CompoundIterator`, which is created by the begin and the end position. 
  - It defines template \<class ForwardIterator> as the type of the begin and 
    the end position , so you should declare the actual type when using 
    `CompoundIterator`.
  - It points to the begin position in function `first`. 
  - It points to next item in function `next`, and it will throw exception if it 
    already points to the end position.
  - It returns the current pointed item in function `currentItem`, and it will 
    throw exception if it points to the end position.
  - It returns the result which checks if it points to the end position in 
    function `isDone`.
- tests of `NullIterator` and `CompoundIterator` should be written in 
  `ut_iterator.h`.
---
- file `utility.h`, where there is a function `SelectShape`, which accepts two
  arguments: a `Shape` object and a constraint, and it will return the first 
  matched `Shape` object.

#### Example:

``` c++
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(1.1));
  cs1->addShape(new Rectangle(3.14 ,4));

  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(new Circle(12.34567))
  cs2->addShape(cs1);
```

result of `cs2.info()`(don't print '\n', it just remind you there has a \n)
```
Compound Shape\n
{\n
Circle(12.35)\n
Compound Shape\n
{\n
Circle(1.10)\n
Rectangle(3.14 4.00)\n
}\n
}
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
- If you don't change the type of `Shape` container in `CompoundShape`, you'll 
  get **NO POINT** for the assignment.
- You don't need to delete the tests written in hw1.
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
  │   └── utility.h
  └── test
      ├── ut_circle.h
      ├── ut_compound_shape.h
      ├── ut_iterator.h
      ├── ut_main.cpp
      ├── ut_rectangle.h
      ├── ut_triangle.h
      ├── ut_two_dimensional_vector.h
      └── ut_utility.h
  ```

## References
- [C++.com](http://www.cplusplus.com/reference/)
- [std::list](http://www.cplusplus.com/reference/list/list/)
- [function templates and class templates](https://www.cplusplus.com/doc/oldtutorial/templates/)

## Course Link
Course Link: https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2021f

## Environment Setting
Tutorial: https://ssl-gitlab.csie.ntut.edu.tw/course/environment_setting.git
