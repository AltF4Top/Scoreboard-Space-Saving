CBF_PATH = ../CountingBF
SSH_PATH = ../SpaceSavingHeap
C_PATH = ../common

all: SSH_CBF.a
 
SSH_CBF.a: SSH_CBF.o $(CBF_PATH)/CountingBF.o $(SSH_PATH)/SpaceSavingHeap.o $(C_PATH)/common.o
#	(cd $(CBF_PATH); make; cd ../SSH_CBF);
#	(cd $(SSH_PATH); make; cd ../SSH_CBF);
#	g++ SSH_CBF.o $(CBF_PATH)/CountingBF.a $(SSH_PATH)/SpaceSavingHeap.a -o SSH_CBF.a
	ar -rcs SSH_CBF.a SSH_CBF.o $(CBF_PATH)/CountingBF.o $(SSH_PATH)/SpaceSavingHeap.o $(C_PATH)/common.o

SSH_CBF.o: SSH_CBF.cpp SSH_CBF.hpp $(CBF_PATH)/CountingBF.h $(SSH_PATH)/SpaceSavingHeap.hpp
	g++ -c SSH_CBF.cpp -o SSH_CBF.o -O2

clean:
	rm SSH_CBF.a SSH_CBF.o

.PHONY: all clean

