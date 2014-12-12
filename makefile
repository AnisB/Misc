
CXX = g++-4.9
FLAG = -std=c++11
all: anagram binaryfromarray doublestar hanoi hashtable instring list matrix queuebystacks removedupli reversechar simplestack simpletree spacereplace stacksorting uniqueString

anagram: 
	${CXX} anagram.cpp -o anagram ${FLAG}

binaryfromarray: 
	${CXX} binaryfromarray.cpp -o binaryfromarray ${FLAG}

doublestar:
	${CXX} doublestar.cpp -o doublestar ${FLAG}

hanoi: 
	${CXX} hanoi.cpp -o hanoi

hashtable:
	${CXX} hashtable.cpp -o hashtable

instring: 
	${CXX} instring.cpp -o instring

list: 
	${CXX} list.cpp -o list

matrix:
	${CXX} matrix.cpp -o matrix

queuebystacks:
	${CXX} queuebystacks.cpp -o queuebystacks

removedupli:
	${CXX} removedupli.cpp -o removedupli

reversechar:
	${CXX} reversechar.cpp -o reversechar

simplestack:
	${CXX} simplestack.cpp -o simplestack

simpletree:
	${CXX} simpletree.cpp -o simpletree

spacereplace:
	${CXX} spacereplace.cpp -o spacereplace ${FLAG}

stacksorting:
	${CXX} stacksorting.cpp -o stacksorting

uniqueString:
	${CXX} uniqueString.cpp -o uniqueString ${FLAG}

clean:
	rm -rf *o anagram binaryfromarray doublestar hanoi hashtable instring list matrix queuebystacks removedupli reversechar simplestack simpletree spacereplace stacksorting uniqueString