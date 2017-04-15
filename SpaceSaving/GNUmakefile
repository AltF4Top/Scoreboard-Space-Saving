SSH_PATH = ../SpaceSavingHeap

.PHONY: all clean

all: SpaceSaving.a

SpaceSaving.a: SpaceSaving.o $(SSH_PATH)/SpaceSavingHeap.o
	ar -rcs SpaceSaving.a SpaceSaving.o $(SSH_PATH)/SpaceSavingHeap.o

SpaceSaving.o: SpaceSaving.cpp SpaceSaving.hpp $(SSH_PATH)/SpaceSavingHeap.hpp
	g++ -c SpaceSaving.cpp -O2 -o SpaceSaving.o

clean:
	rm SpaceSaving.a SpaceSaving.o
