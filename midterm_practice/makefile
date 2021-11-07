# tag what targets are commands
.PHONY: clean all

# execute all commands
all: directory ut_all

# create a bin directory
directory:
	mkdir -p bin

# execution file,
# -Wall: This enables all the warnings about constructions that some users consider questionable
# -Wfatal-errors: This option causes the compiler to abort compilation on the first error occurred rather than trying to keep going and printing further error messages.
# reference: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
ut_all: test/ut_main.cpp $(TEST) $(SRC_HEADER)
	g++ -std=c++11 -Wall -Wfatal-errors test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

# Source file (including header)
SRC_HEADER= src/shape.h src/circle.h src/rectangle.h src/twoDimensionVector.h src/triangle.h \
				src/iterator/null_iterator.h src/compound_shape.h src/iterator/compound_iterator.h \
				src/visitor/shape_visitor.h src/visitor/select_shape_visitor.h

# Test file (including header and cpp)
TEST= test/ut_circle.h test/ut_rectangle.h test/ut_twoDimensionVector.h test/ut_triangle.h \
		test/ut_null_iterator.h test/ut_compound_shape.h test/ut_compound_iterator.h \
		test/ut_select_shape_visitor.h

# clear the bin directory recursively
clean:
	rm -rf bin