# Pattern Oriented Software Design 2021 Fall Assignment

## Assignment 2

__Deadline__: 10/18 23:59.

The folders src/ and test/ in this repo contain the template code of the
assignment, which is just the skeleton. You need to finish the implementation. 

For this assignment, you are asked to implement a simple markdown generator. In
this system, there are three classes `Paragraph`, `ListItem` and `Text` which are all
derived from abstract class `Article`.

Please add to the skeleton code so that it meets the specifications below.
- The abstract class `Article` has three methods `getText()`, `getLevel()` and 
  `add()`.
- The classes `Text`, `Paragraph` and `ListItem` that are derived from
  abstract class `Article`. 
- For class `Text`, which has the string data member `text` and has a constant level of 0, calling
  `getText()` returns `text` and calling `add()` throws an exception.
- For class `ListItem`, the string data member `text` and has a constant level of 0,
  calling `getText()` returns `text` prefixed with '- ' and calling `add()` throws an exception.
- For class `Paragraph`, which the string data member `text` and non-constant level greather than
  1 but smaller or equal than 6, Paragraph can aggregate 0 to n `Article` objects, and calling `getText()` does the following: first, a
  numbers of '#' equal to level is prefixed to `text`; and all children's 
  `getText()` are called with the result postfixed with '\n'. Note that the last line should not have a '\n' at the end.
- `Paragraph` of level _m_ can be added to a `Paragraph` of level _n_ only if _m_ is greater than _n_; otherwise, an exception is thrown.

#### Example:

``` c++
  Paragraph p(1, "title");
  p.add(new ListItem("list1"));
  p.add(new ListItem("list2"));
  p.add(new Text("text"));
  Paragraph* p2 = new Paragraph(2, "title2");
  p2->add(new ListItem("list3"));
  p2->add(new ListItem("list4"));
  p2->add(new Text("sub text"));
  p.add(p2);
```

result of `p.getText()`(don't print '\n', it just remind you there has a \n)
```
# title\n
- list1\n
- list2\n
text\n
## title2\n
- list3\n
- list4\n
sub text
```

#### Notes:
- If your code fails to compile on the Jenkins server, you'll get **NO POINT** for
the assignment.
- Your program should be able to handle unexpected input data, that is, you
should do error handling if necessary.
- You should make your unit test fail if the program that should throw an exception
runs without throwing one.
- When writing unit tests, you should take as many situations as possible into
consideration.
- Discussion is encouraged but the pushed code must be your own.
- Any submission after deadline will not be graded.

#### Hints:
- You can use `typeid` to check type.

### Grading Rubrics
1. Unit tests written by yourself: 50%. (You have to write tests covering all 
conditions, and make them pass.)
2. Unit tests written by TA: 50%.

### File Structure

  ```bash
    .
    ├── makefile
    ├── src
    │   ├── article.h
    │   ├── list_item.h
    │   ├── paragraph.h
    │   └── text.h
    └── test
        ├── ut_list_item.h
        ├── ut_main.cpp
        ├── ut_paragraph.h
        └── ut_text.h
  ```

## References
- [C++.com](http://www.cplusplus.com/reference/)
- [C++ Exception Handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)
- [Makefile Tutorial](https://ssl-gitlab.csie.ntut.edu.tw/course/makefile_tutorial)

## Course Link
Course Link: https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2021f

## Environment Setting
Tutorial: https://ssl-gitlab.csie.ntut.edu.tw/course/environment_setting.git
