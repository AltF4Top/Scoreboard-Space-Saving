#include "SpaceSavingHeap.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <new>

SpaceSavingHeap ::
SpaceSavingHeap(uint32_t _k): k(_k), HEAPSIZE(HEAPSIZESCALE * k){
	hn = 0;
	heap = new heap_node[HEAPSIZE + 1];
}

SpaceSavingHeap ::
~SpaceSavingHeap(){
	for (uint32_t i = 1; i <= hn; ++i)
		delete heap[i].key;
	delete []heap;
}

void SpaceSavingHeap ::
surface(uint32_t x){
	uint32_t f;
	heap_node t = heap[x];
	while (f = x >> 1){
		if (heap[f].cnt <= t.cnt) break;
		heap[x] = heap[f]; x = f;
	}
	heap[x] = t;
}

void SpaceSavingHeap ::
sink(uint32_t x){
	uint32_t c;
	uint32_t t = heap[x];
	while ((c = x << 1) <= hn){
		if (c < hn && heap[c].cnt < heap[c+1].cnt) ++c;
		if (t.cnt <= heap[c].cnt) break;
		heap[x] = heap[c]; x = c;
	}
	heap[x] = t;
}

void SpaceSavingHeap ::
insert(const string &key, uint32_t cnt){
	for (uint32_t i = 0; i < hn; ++i)
	 if (*(heap[i].key) == key){
		heap[i].cnt += cnt;
		sink(i);
		return ;
	 }
	
	if (hn < HEAPSIZE){
		++hn;
		heap[i].key = new string(key);
		heap[hn].cnt = cnt;
	} else {
		uint32_t t = heap[1];
		*(heap[t].key) = key; ++heap[t].cnt;
		sink(1);
	}
}

void SpaceSavingHeap ::
GetTopK(string *Ans){
	for (uint32_t t = 0; t < k; ++t){
		uint32_t p;
		for (uint32_t i = 0; i < k; ++i)
		 if (heap[p].cnt < heap[i].cnt)
			p = i;
		Ans[t] = heap[p].key;
		heap[p].cnt = 0;
	}
}

