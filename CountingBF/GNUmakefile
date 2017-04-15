
CommonPath = ../common

.PHONY: all clean

all: CountingBF.a

CountingBF.a: CountingBF.o $(CommonPath)/common.a
	(cd ../common; make; cd ../CountingBF)
	ar -rcs CountingBF.a CountingBF.o $(CommonPath)/common.a

CountingBF.o: CountingBF.cpp CountingBF.h $(CommonPath)/common.h
	g++ -c CountingBF.cpp -O2 -o CountingBF.o

clean:
	rm CountingBF.o CountingBF.a

