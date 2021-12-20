# This is an example about how the program work.

## 1. Run program(bin/main):

```
$ make
$ bin/main
...
Please enter the following instruction number number to start building: 
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```

## 2. Enter instruction: 1 (add circle)
```
1
Please enter the information of circle:
Radius of circle: 1
Circle added.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```

## 3. Enter instruction: 2 (add rectangle)
```
2
Please enter the information of rectangle:
Width of rectangle: 1
Height of rectangle: 1
Rectangle added.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```

## 4. Enter instruction: 3 (add triangle)
```
3
Please enter the information of triangle:
X1 of triangle: 0
Y1 of triangle: 1
X2 of triangle: 1
Y2 of triangle: 0
Invalid argument. Please try again.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```

## 5. Enter instruction: 4 (add compound)
```
4
Please enter the following instruction number to build the compound:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'exit': to exit the program
1
Please enter the information of circle:
Radius of circle: 1
Circle added.
Please enter the following instruction number to build the compound:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'exit': to exit the program
5
Compound added.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```

## 6. Enter instruction: 5 (save)
```
5
Please enter the file name to save the shape:
output
Save complete.
Please enter the following instruction number to start building: 
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```
### 6-1. Sample output
```
CompoundShape {
  Circle (12.35)
  CompoundShape {
    Circle (1.10)
    Rectangle (3.14 4.00)
  }
}
```

## 7. Enter instruction: 6 (exit) to terminate the program

## 8. Exceptions
### 8-1. Enter instruction: `not an instruction`
```
8
Invalid instruction. Please try again.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```

### 8-2. Build fail
```
1
Please enter the information of circle:
Radius of circle: -1
Invalid argument. Please try again.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
2
Please enter the information of rectangle:
Width of rectangle: -1
Height of rectangle: -1
Invalid argument. Please try again.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
3
Please enter the information of triangle:
X1 of triangle: 1
Y1 of triangle: 1
X2 of triangle: 2
Y2 of triangle: 2
Invalid argument. Please try again.
Please enter the following instruction number to start building:
  1. 'add circle': to add a circle
  2. 'add rectangle': to add a rectangle
  3. 'add triangle': to add a triangle
  4. 'add compound': to add a compound
  5. 'save': output shape to file
  6. 'exit': to exit the program
```
