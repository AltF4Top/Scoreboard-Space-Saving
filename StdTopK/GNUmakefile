HT_PATH = ../HashTable
C_PATH = ../common

.PHONY: all clean

all: StdTopK.a

StdTopK.a: StdTopK.o $(HT_PATH)/HashTable.o $(C_PATH)/common.o
#	(cd ../HashTable; make; cd ../StdTopK;)
	ar -rcs StdTopK.a StdTopK.o $(HT_PATH)/HashTable.o $(C_PATH)/common.o

StdTopK.o: StdTopK.cpp StdTopK.hpp
	g++ -c StdTopK.cpp -o StdTopK.o -O2

clean:
	rm StdTopK.a StdTopK.o
