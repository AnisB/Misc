OS := $(shell uname)
ifeq ($(OS), Darwin)
OPENCL= -framework OpenCL
CXX = g++-4.9
else
OPENCL= -lOpenCL
CXX = g++
endif
FLAG = -std=c++11
PROF = -pg

all: anagram binaryfromarray doublestar hanoi hashtable instring list matrix queuebystacks removedupli reversechar simplestack simpletree spacereplace stacksorting uniqueString simpleopenmp

anagram: anagram.cpp
	${CXX} anagram.cpp -o anagram ${FLAG}

binaryfromarray: binaryfromarray.cpp
	${CXX} binaryfromarray.cpp -o binaryfromarray ${FLAG}

doublestar: doublestar.cpp
	${CXX} doublestar.cpp -o doublestar ${FLAG}

hanoi: hanoi.cpp
	${CXX} hanoi.cpp -o hanoi ${FLAG}

hashtable: hashtable.cpp
	${CXX} hashtable.cpp -o hashtable ${FLAG}

instring: instring.cpp
	${CXX} instring.cpp -o instring ${FLAG}

list: list.cpp
	${CXX} list.cpp -o list ${FLAG}

matrix: matrix.cpp
	${CXX} matrix.cpp -o matrix ${FLAG}

queuebystacks: queuebystacks.cpp
	${CXX} queuebystacks.cpp -o queuebystacks ${FLAG}

removedupli: removedupli.cpp
	${CXX} removedupli.cpp -o removedupli ${FLAG}

reversechar: reversechar.cpp
	${CXX} reversechar.cpp -o reversechar ${FLAG}

simplestack: simplestack.cpp
	${CXX} simplestack.cpp -o simplestack ${FLAG}

simpletree: simpletree.cpp
	${CXX} simpletree.cpp -o simpletree ${FLAG}

spacereplace: spacereplace.cpp
	${CXX} spacereplace.cpp -o spacereplace ${FLAG}

stacksorting: stacksorting.cpp
	${CXX} stacksorting.cpp -o stacksorting ${FLAG}

uniqueString: uniqueString.cpp
	${CXX} uniqueString.cpp -o uniqueString ${FLAG}

#simpleopencl: simpleopencl.cpp
#	${CXX} simpleopencl.cpp -o simpleopencl ${FLAG} ${OPENCL}

simpleopenmp: simpleopenmp.cpp
	${CXX} simpleopenmp.cpp -o simpleopenmp ${FLAG} -fopenmp ${PROF}

clean:
	rm -rf *o anagram binaryfromarray doublestar hanoi hashtable instring list matrix queuebystacks removedupli reversechar simplestack simpletree spacereplace stacksorting uniqueString simpleopenmp #simpleopencl 