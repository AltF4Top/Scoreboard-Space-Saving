#include "SpaceSavingHeap.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <new>

SpaceSavingHeap ::
SpaceSavingHeap(uint32_t _k, uint32_t _hsize): k(_k), hn(0), hsize(_hsize){
	heap = new node[hsize + 1];
	puts("old");
	memset(hash, 0, HashRange);
}

SpaceSavingHeap ::
~SpaceSavingHeap(){
	for (uint32_t i = 1; i <= hsize; ++i)
	 if (heap[i].key == NULL) delete []heap[i].key;
	delete []heap;
}

void SpaceSavingHeap ::
surface(uint32_t x){
	struct node t = heap[x];
	*(t.pprev) = &t;
	if (t.next)
		t.next -> pprev = &t.next;
	
	uint32_t f;
	while (f = x >> 1){
		if (heap[f].cnt <= t.cnt) break;
		
		heap[x] = heap[f];
		*(heap[x].pprev) = &heap[x];
		if (heap[x].next)
			heap[x].next -> pprev = &heap[x].next;
			
		x = f;
	}
	heap[x] = t;
	*(heap[x].pprev) = &heap[x];
	if (heap[x].next)
		heap[x].next -> pprev = &heap[x].next;
}

void SpaceSavingHeap ::
sink(uint32_t x){
	struct node t = heap[x];
	*(t.pprev) = &t;
	if (t.next)
		t.next -> pprev = &t.next;
	
	uint32_t c;
	while ((c = x << 1) <= hn){
		if (c < hn && heap[c].cnt > heap[c+1].cnt) ++c;
		if (t.cnt <= heap[c].cnt) break;
		
		heap[x] = heap[c];
		*(heap[x].pprev) = &heap[x];
		if (heap[x].next)
			heap[x].next -> pprev = &heap[x].next;
		
		x = c;
	}
	
	heap[x] = t;
	*(heap[x].pprev) = &heap[x];
	if (heap[x].next)
		heap[x].next -> pprev = &heap[x].next;
}

void SpaceSavingHeap ::
insert(const char *key, uint32_t cnt){
/*
	uint32_t T_T = 0;
	for (uint32_t t = 0; t < HashRange; ++t)
		for (struct node *p = hash[t]; p; p = p -> next){
			if (t != hashfunc.Str2Int((cuc *)p -> key, 1, strlen(p -> key)) % HashRange)
				puts("!!!! warning !!!!");
			++T_T;
		}
	if (T_T != hn) puts("!!!! warning !!!!");
	for (uint32_t t = 1; t <= hn >> 1; ++t){
		if (heap[t].cnt > heap[t*2].cnt || (t*2<hn && heap[t].cnt > heap[t*2+1].cnt))
			puts("!!!! warning !!!!");
	}
*/	
	int index = hashfunc.Str2Int((cuc *)key, 1, strlen(key)) % HashRange;
	
	struct node *p, **pp;
	for (pp = &hash[index], p = *pp; p; pp = &p -> next, p = *pp){
		//printf("p = %p\n", p);
		if (strcmp(p -> key, key) == 0){
			p -> cnt += cnt;
			sink(p - heap);
			delete []key;
			return ;
		}
	}
	
	//puts("SSHinsert: find finish");
	if (hn < hsize){
		p = &heap[++hn];
		p -> key = key; p -> cnt = cnt;
		p -> next = NULL;
		p -> pprev = pp; *pp = p;
		//puts("surface");
		surface(hn);
	} else {
		p = &heap[1]; delete []p -> key;
		p -> key = key; p -> cnt += cnt;
		
		if (p -> next)
			p -> next -> pprev = p -> pprev;
		*(p -> pprev) = p -> next;
		
		if (pp != &p -> next){
			*pp = p; p -> pprev = pp;
		}
		p -> next = NULL;
		//puts("sink");
		sink(1);
	}
}

void SpaceSavingHeap ::
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

