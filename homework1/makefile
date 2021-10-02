.PHONY: clean

TEST= test/ut_circle.h test/ut_rectangle.h test/ut_two_dimensional_vector.h \
		test/ut_triangle.h
SRC= src/shape.h src/circle.h src/rectangle.h src/two_dimensional_vector.h src/triangle.h

bin/ut_all: test/ut_main.cpp $(TEST) $(SRC) # what target depends on
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/ut_all
