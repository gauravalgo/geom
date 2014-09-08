
INC := ./inc
TESTS := ./tests

CXX := clang++
CXX_FLAGS := -Wall --std=c++11 -I${INC}
LINK_FLAGS := 

TEST_OBJECTS := $(patsubst %.cpp,%.o,$(wildcard ${TESTS}/*.cpp))

.PHONEY: all tests clean documentation

all: tests
tests: test
clean:
	rm -rf ${TESTS}/*.o
	rm -rf ./test
	rm -rf ./html/ ./latex

documentation:
	doxygen

test: ${TEST_OBJECTS}
	${CXX} ${LINK_FLAGS} -o ./test ${TEST_OBJECTS} -lgtest -lgtest_main

%.o: %.cpp
	${CXX} -c ${CXX_FLAGS} -o $@ $<
