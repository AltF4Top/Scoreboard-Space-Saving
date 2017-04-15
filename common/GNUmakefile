.PHONY: all clean

all: common.a

common.a: common.o
	ar -rcs common.a common.o
common.o: common.cpp common.h
	g++ -c common.cpp -O2 -o common.o

clean:
	rm common.a common.o
