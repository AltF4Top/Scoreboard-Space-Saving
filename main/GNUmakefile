SS_PATH = ../SpaceSaving
SSH_CBF_PATH = ../SSH_CBF
StdTopK_PATH = ../StdTopK
Debug_PATH = ../debug

.PHONY: all clean

all: main

main: main.o $(SSH_CBF_PATH)/SSH_CBF.a $(StdTopK_PATH)/StdTopK.a
#	(cd $(SSH_CBF_PATH); make; cd ../main;)
#	(cd $(StdTopK_PATH); make; cd ../main;)
	g++ main.o $(SS_PATH)/SpaceSaving.a $(SSH_CBF_PATH)/SSH_CBF.a $(StdTopK_PATH)/StdTopK.a -o main -O2
#	g++ main.o $(SS_PATH)/SpaceSaving.a $(Debug_PATH)/debug_SS.a $(StdTopK_PATH)/StdTopK.a -o main -O2

main.o: main.cpp config.hpp $(SSH_CBF_PATH)/SSH_CBF.hpp $(StdTopK_PATH)/StdTopK.hpp $(SS_PATH)/SpaceSaving.hpp
	g++ -c main.cpp -O2 -o main.o

clean:
	rm main main.o

