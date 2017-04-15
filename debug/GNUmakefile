.PHONY: all clean

all: debug_SS.a

debug_SS.a: debug_SS.o debug_SSH.o
	ar -rcs debug_SS.a debug_SS.o debug_SSH.o

debug_SS.o: debug_SS.cpp debug_SS.hpp debug_SSH.hpp
	g++ -c debug_SS.cpp -o debug_SS.o -O2

debug_SSH.o: debug_SSH.cpp debug_SSH.hpp
	g++ -c debug_SSH.cpp -o debug_SSH.o -O2

clean:
	rm debug_SS.a debug_SS.o debug_SSH.o

