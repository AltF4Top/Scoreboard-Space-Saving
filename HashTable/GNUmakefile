COMMON_PATH = ../common

.PHONY: all clean

all: HashTable.a

HashTable.a: HashTable.o $(COMMON_PATH)/common.a
	(cd ../common; make; cd ../HashTable;)
	ar -rcs HashTable.a HashTable.o $(COMMON_PATH)/common.a

HashTable.o: HashTable.cpp HashTable.h
	g++ -c HashTable.cpp -O2 -o HashTable.o

clean:
	rm HashTable.a HashTable.o
