#include "SpaceSaving.hpp"

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
	heap.insert(tkey, 1);
}

void SS ::
GetTopK(const char **Ans){
	heap.GetTopK(Ans);
}
