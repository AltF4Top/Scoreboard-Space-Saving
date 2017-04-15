CPATH = ../common

.PHONY: all clean

all: SpaceSavingHeap.a

SpaceSavingHeap.a: SpaceSavingHeap.o $(CPATH)/common.a
	(cd ../common; make; cd ../SpaceSavingHeap;)
	ar -rcs SpaceSavingHeap.a SpaceSavingHeap.o $(CPATH)/common.a

SpaceSavingHeap.o: SpaceSavingHeap.cpp SpaceSavingHeap.hpp $(CPATH)/common.h $(CPATH)/forward.hpp
	g++ -c -O2 SpaceSavingHeap.cpp -o SpaceSavingHeap.o

clean:
	rm SpaceSavingHeap.a SpaceSavingHeap.o
