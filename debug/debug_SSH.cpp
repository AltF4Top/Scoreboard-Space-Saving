#include "debug_SSH.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <new>

debug_SSH ::
debug_SSH(uint32_t _k, uint32_t _hsize): k(_k), hn(0), hsize(_hsize){
	heap = new node[hsize + 1];
}

debug_SSH ::
~debug_SSH(){
	for (uint32_t i = 1; i <= hsize; ++i)
	 if (heap[i].key == NULL) delete []heap[i].key;
	delete []heap;
}

void debug_SSH ::
surface(uint32_t x){
	struct node t = heap[x];
	
	uint32_t f;
	while (f = x >> 1){
		if (heap[f].cnt <= t.cnt) break;
		heap[x] = heap[f];
		x = f;
	}
	heap[x] = t;
}

void debug_SSH ::
sink(uint32_t x){
	struct node t = heap[x];
	uint32_t c;
	while ((c = x << 1) <= hn){
		if (c < hn && heap[c].cnt > heap[c+1].cnt) ++c;
		if (t.cnt <= heap[c].cnt) break;
		heap[x] = heap[c];
		x = c;
	}
	heap[x] = t;
}

void debug_SSH ::
insert(const char *key, uint32_t cnt){
	for (uint32_t i = 1; i <= hn; ++i)
		if (strcmp(key, heap[i].key) == 0){
			heap[i].cnt += cnt;
			sink(i);
			return ;
		}
	
	struct node *p;
	if (hn < hsize){
		p = &heap[++hn];
		p -> key = key; p -> cnt = cnt;
		surface(hn);
	} else {
		p = &heap[1]; delete p -> key;
		p -> key = key; p -> cnt += cnt;
		sink(1);
	}
}

void debug_SSH ::
GetTopK(const char **Ans){

	for (uint32_t t = 0; t < k; ++t){
		uint32_t p = 1;
		for (uint32_t i = 1; i <= hn; ++i)
		 if (heap[p].cnt < heap[i].cnt)
			p = i;
		Ans[t] = heap[p].key;
		heap[p].cnt = 0;
		heap[p].key = NULL;
	}
}

