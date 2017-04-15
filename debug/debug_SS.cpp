#include "debug_SS.hpp"

#include <cstring>
#include <new>

debug_SS :: 
debug_SS(uint32_t _k, uint32_t _hsize): heap(_k, _hsize){
}

debug_SS :: 
~debug_SS(){
}

void debug_SS ::
insert(const char *key){
	char *tkey = new char[strlen(key) + 1];
	strcpy(tkey, key);
	heap.insert(tkey, 1);
}

void debug_SS ::
GetTopK(const char **Ans){
	heap.GetTopK(Ans);
}
