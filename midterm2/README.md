# Pattern Oriented Software Design 2021 Fall Lab2

__Deadline__: 12/29 18:00~21:00

The folders `src/` and `test/` in this repo contain the template code of this 
exam, which is just the skeleton. You need to finish the implementation. 

## Table of Contents
- [Allowed Resources](#allowed-resources)
- [Specs](#specs)
  - [Composite](#composite-5)
  - [Iterator](#iterator-5)
  - [Visitor](#visitor-5)
  - [Builder](#builder-15)
  - [Singleton](#singleton-10)
- [Notes](#notes)
- [Grading Rubrics](#grading-rubrics)
- [File Structure](#file-structure)

## Allowed Resources
You can use following resources to complete the midterm problems.
- [C++.com](http://www.cplusplus.com/reference/)
- [Dictionary](https://dictionary.cambridge.org/zht/)
- Your own code from [GitLab](https://ssl-gitlab.csie.ntut.edu.tw)
- [Course Repo](https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2021f)
- [Jenkins](https://ssl-jenkins.csie.ntut.edu.tw/)
- All the other resources are not allowed.

## Specs
Please complete the given code to satisfy all the specs of the `Article` problem
and the following conditions.

### Composite (5%)
- The abstract class `Article` has five methods `getText()`, `getLevel()`,
  `add()`, `createIterator()` and `accept()`.
- The classes `Text`, `Paragraph` and `ListItem` are subclasses derived from
  abstract class `Article`.
- Class `Text` has the string data member `text` and a constant
  level of 0. Calling `getText()` returns `text`, calling `add()` throws an
  exception, and calling `createIterator()` returns a `NullIterator`.
- Class `ListItem` has the string data member `text` and a constant level of 0.
  Calling `getText()` returns `text`,  calling `add()` throws
  an exception, and calling `createIterator()` returns a `NullIterator`.
- Class `Paragraph` has the string data member `text` and a non-constant level 
  greater or equal than 1 but smaller than or equal to 6. A `Paragraph` object 
  can aggregate an arbitrary number of `Article` objects. Calling `getText()` 
  returns its own `text`. Calling `createIterator()` returns a 
  `CompoundIterator`.
- A `Paragraph` object of level _m_ can be added to a `Paragraph` object of 
  level _n_ only if _m_ is greater than _n_; otherwise, an exception is thrown.

### Iterator (5%)
- Abstract class `Iterator`, which defines four pure virtual functions `first`, 
  `currentItem`, `next` and `isDone`.
- Both class `NullIterator` and `CompoundIterator` are derived from
  `Iterator`. They should implement all pure virtual functions defined in 
  `Iterator`.
- Class `NullIterator` doesn't point to any object, so it will throw 
  exception when its functions `first`, `currentItem` and `next` are called. 
  The function `isDone` always return `true`.
- Class `CompoundIterator` has a constructor that is called by an object of 
  class `Paragraph`, which passes in the begin and the end position of the 
  `Article` objects it aggregates. Further,
  - Class `CompoundIterator` defines template \<class ForwardIterator> as the 
    type parameter for the begin and the end position:  
    ``` c++
    template <class ForwardIterator>
    class CompoundIterator : public Iterator {
      CompoundIterator(ForwardIterator begin, ForwardIterator end) ...
      ...
    };
    ```
  _Hint: The type parameter `ForwardIterator` should be able to accept iterators_
  _created by vector or list in the standard template library._
  - A `CompoundIterator` object points to the begin position when it is created.
  - A `CompoundIterator` object points to the begin position with function 
    `first`. 
  - A `CompoundIterator` object points to next item with function `next`, and it 
    will throw exception if it already points to the end position.
  - A `CompoundIterator` object returns the current pointed-to item in function 
    `currentItem`, and it will throw exception if it points to the end position.
  - A `CompoundIterator` object returns `true` if it points to the end position 
    with function `isDone`.

### Visitor (5%)
- Abstract class `ArticleVisitor` defines four pure virtual functions 
  `visitListItem`, `visitText`, `visitParagraph` and `getResult`.
- Classes `MarkdownVisitor` and `HtmlVisitor`, both of which are derived from
  `ArticleVisitor`, implement all pure functions defined in `ArticleVisitor`.
- Class `MarkdownVisitor` generates markdown document in following rule:
  - it generates `- ${text}\n` when visiting `ListItem`
  - it generates `${text}\n` when visiting `Text`
  - when visiting `Paragraph`, first, a numbers of '#' equal to `level` is 
    prefixed to its own `text`; `texts` of the `Article` objects it aggregates 
    are then joined, finally, the whole string is postfixed with '\n'.
- Class `HtmlVisitor` generate html document in following rule:
  - it generates `<li>${text}</li>` when visiting `ListItem`
  - it generates `<span>${text}</span>` when visiting `Text`
  - when visiting `Paragraph`, first, wrap `text` inside tags 
    `<h${level}>...</h${level}>`, where `level` is the level of the `Paragraph` 
    object; second, join the results generated for the `Article` objects it 
    aggregates and wrap then inside tags `<div> ...</div>`.

#### MarkdownVisitor Example:
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
  MarkdownVisitor visitor;
  p.accept(&visitor);
```

result of `visitor.getResult()`
(don't print '\n', it just remind you there has a \n)
```
# title\n
- list1\n
- list2\n
text\n
## title2\n
- list3\n
- list4\n
sub text\n
```

#### HtmlVisitor Example:
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
  HtmlVisitor visitor;
  p.accept(&visitor);
```

result of `visitor.getResult()`
```
<div><h1>title</h1><li>list1</li><li>list2</li><span>text</span><div><h2>title2</h2><li>list3</li><li>list4</li><span>sub text</span></div></div>
```

### Builder (15%)
- class `ArticleBuilder`, which builds `Article` object with arguments and 
  pushes the object into a result stack.
  - it needs **text** when building `ListItem`.
  - it needs **text** when building `Text`.
  - it needs **level** and **text** when building `Paragraph`, and pushes 
    a new `Paragraph` into the result stack in the beginning; 
    it adds all the `Article` objects pushed after the `Paragraph` into the 
    `Paragraph` in the end.
  - it returns the top of the result stack in function `getArticle`.
  - it cleans up all the `Article` objects in the result stack in function 
    `reset()`, and you don't have to test this function.
  - you don't need to verify if arguments are valid in `ArticleBuilder`.
- class `ArticleScanner`, which scans through the input and extracts integers, 
  strings and tokens in token list defined by TA.
  - token list: {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"}
  - it points to next token in function `nextToken`.
  - it points to next integer in function `nextInt`.
  - it points to next string surrounded by `"` in function `nextStr`.
  - it will throw exception if it already points to the end position of the 
    input in function `nextToken`, `nextInt` and `nextStr`
  - it returns the result which checks if it points to the end position of the 
    input after skipping white space in function `isDone`, where white space 
    includes " ", "\n" and "\t".
  - you should ignore the token which is illegal.
    ```
    // Example
    std::string input = "I ListItem eee {\"string\"555\"next\"}too6a";
    ArticleScanner scanner(input);
    std::string first = scanner.nextToken();     // `first` is "ListItem"
    std::string second = scanner.nextStr();      // `second` is "string"
    std::string third = scanner.nextToken();     // `third` is "}"
    int fourth = scanner.nextInt();              // `fourth` is 6
    ```
  _Hint: You can use a flag to check if double quotes are closed in function_
  _`nextStr`._
- class `ArticleParser`, which accepts a file path, that is a relative path of 
  `makefile`, and uses scanner as well as builder to parse a `Article` object in 
  the file.
  - it creates scanner in the constructor.
  - it handles the logic of parsing in function `parse`. 
  - it returns the `Article` object built by the builder and reset the builder 
    in function `getArticle`.

### Singleton (10%)
- class `ArticleBuilder`, which has only one instance in the system, and others 
  can only use `getInstance` to get its instance. 

## Notes
- If your code fails to compile on the 
  [Jenkins](https://ssl-jenkins.csie.ntut.edu.tw/) server, you'll get 
  **NO POINT** for the test.
- Your program should be able to handle unexpected input data, that is, you
  should do error handling if necessary.
- You should make your unit test fail if the program that should throw an 
  exception runs without throwing one.
- When writing unit tests, you should take as many situations as possible into
  consideration.
- Any submission after end time of test will not be graded.
- Remember to **RELEASE THE SPACE** you allocate after using it.
- The folder `test/data/` is not necessary, but you can take it for reference.
- Commit and push your code early and often.

## Grading Rubrics
1. Unit tests written by yourself: 30%.
2. Unit tests written by TA: 30%.
3. Correctly implement `Composite` pattern: 5%.
4. Correctly implement `Iterator` pattern: 5%.
5. Correctly implement `Visitor` pattern: 5%.
6. Correctly implement `Builder` pattern: 15%.
7. Correctly implement `Singleton` pattern: 10%.

## File Structure
  ```bash
  .
  ├── makefile
  ├── src
  │   ├── article.h
  │   ├── builder
  │   │   ├── article_builder.h
  │   │   ├── article_parser.h
  │   │   └── article_scanner.h
  │   ├── iterator
  │   │   ├── compound_iterator.h
  │   │   ├── iterator.h
  │   │   └── null_iterator.h
  │   ├── list_item.h
  │   ├── paragraph.h
  │   ├── text.h
  │   └── visitor
  │       ├── article_visitor.h
  │       ├── html_visitor.h
  │       └── markdown_visitor.h
  └── test
      ├── builder
      │   ├── ut_article_builder.h
      │   ├── ut_article_parser.h
      │   └── ut_article_scanner.h
      ├── data
      │   ├── complex_paragraph.txt
      │   ├── empty_paragraph.txt
      │   ├── list_item.txt
      │   ├── simple_paragraph.txt
      │   └── text.txt
      ├── iterator
      │   ├── ut_compound_iterator.h
      │   └── ut_null_iterator.h
      ├── ut_list_item.h
      ├── ut_main.cpp
      ├── ut_paragraph.h
      ├── ut_text.h
      └── visitor
          ├── ut_html_visitor.h
          └── ut_markdown_visitor.h
  ```