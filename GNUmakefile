
.PHONY: all run lib clean

all: run

run: lib
	@(cd main; make;)
	@echo '************************'
	@echo '*  Now running ./main  *'
	@echo '************************'
	@./main/main

lib:
	@(cd common; make; cd ..)
	@(cd CountingBF; make ; cd ..)
	@(cd SpaceSavingHeap; make; cd ..)
	@(cd SpaceSaving; make; cd ..)
	@(cd SSH_CBF; make; cd ..)
	@(cd debug; make; cd ..)
	@(cd StdTopK; make; cd ..)

clean:
	@(cd common; make clean; cd ..)
	@(cd CountingBF; make clean; cd ..)
	@(cd SpaceSavingHeap; make clean; cd ..)
	@(cd SpaceSaving; make clean; cd ..)
	@(cd SSH_CBF; make clean; cd ..)
	@(cd debug; make clean; cd ..)
	@(cd StdTopK; make clean; cd ..)
