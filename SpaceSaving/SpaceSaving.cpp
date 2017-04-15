#include "SpaceSaving.hpp"

#include <cstdio>
#include <cstring>
#include <new>

SS :: 
SS(uint32_t _k, uint32_t _hsize): heap(_k, _hsize){
}

SS :: 
~SS(){
}

void SS ::
insert(const char *key){
	char *tkey = new char[strlen(key) + 1];
	strcpy(tkey, key);
	heap.insert(tkey);
}

void SS ::
GetTopK(char **Ans) const{
	heap.GetTopK(Ans);
}

void SS ::
GetFreq(uint32_t limit, char **Ans) const{
	heap.GetFreq(limit, Ans);
}

uint32_t SS ::
query(const char *key) const{
	return heap.query(key);
}
