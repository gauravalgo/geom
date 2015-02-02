
INC := ./inc
TESTS := ./tests

CXX := g++
CXX_FLAGS := -Wall --std=c++11 -I${INC}
# GTEST_INCLUDE should evaluate to the folder holding the root gtest folder
# such that includes of the form:
#   #include <gtest/gtest.h>
# will work properly.
ifdef GTEST_INCLUDE
CXX_FLAGS := ${CXX_FLAGS} -I${GTEST_INCLUDE}
endif
ifdef GTEST_LIBRARY
LINK_FLAGS := -L${GTEST_LIBRARY}
else
LINK_FLAGS := 
endif

INSTALL_PROGRAM := cp -R

GTEST_LIBS := -lgtest -lgtest_main -lpthread

TEST_OBJECTS := $(patsubst %.cpp,%.o,$(wildcard ${TESTS}/*.cpp))

.PHONEY: all tests clean documentation install user-install doinstall link copy

all: tests
tests: test
clean:
	rm -rf ${TESTS}/*.o
	rm -rf ./test
	rm -rf ./html/ ./latex

link:
	$(eval INSTALL_PROGRAM=ln -s)

copy:
	$(eval INSTALL_PROGRAM=cp -R)

install: INSTALL_PREFIX := /usr/local/include
install: doinstall

user-install: INSTALL_PREFIX := ~/include
user-install: doinstall

doinstall:
	[ -e ${INSTALL_PREFIX} ] && rm -rf ${INSTALL_PREFIX}/geom
	${INSTALL_PROGRAM} ${INC}/geom ${INSTALL_PREFIX}/geom

documentation:
	doxygen

test: ${TEST_OBJECTS}
	${CXX} ${LINK_FLAGS} -o ./test ${TEST_OBJECTS} ${GTEST_LIBS}

%.o: %.cpp
	${CXX} -c ${CXX_FLAGS} -o $@ $<
