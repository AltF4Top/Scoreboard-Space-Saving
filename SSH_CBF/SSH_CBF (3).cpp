#include <cstddef>
#include <cstdio>
#include <cstring>

#include "SSH_CBF.hpp"

#include "../SpaceSavingHeap/SpaceSavingHeap.hpp"
#include "../CountingBF/CountingBF.h"

SSH_CBF ::
SSH_CBF(uint32_t k, uint32_t hsize, uint32_t nhf, uint32_t width, uint32_t nbit, uint32_t qlen, uint32_t _m, uint32_t _M):
	heap(k, hsize), filter(nhf, width, nbit), qh(0), qt(0), QSIZE(qlen), m(_m), M(_M){
	Que = new const char *[QSIZE];
	for (uint32_t i = 0; i < QSIZE; ++i)
		Que[i] = new char[14];
}

SSH_CBF ::
~SSH_CBF(){
	for (uint32_t i = 0; i < QSIZE; ++i)
		delete []Que[i];
	delete []Que;
}

void SSH_CBF ::
push(const char *key){
	strcpy((char *)Que[qt], key);
	qt = (qt + 1) % QSIZE;
}

void SSH_CBF ::
pop(){
	const char *key = Que[qh];
	
	uint32_t t = filter.Query((cuc *)key);
	if (t <= m){
//		filter.Delete((cuc *)key, t);
		filter.Delete((cuc *)key, 1);
	} else if (t >= M){
/*
		while (t--){
				heap.insert(key);
		}
*/
		heap.insert(key);
	}
	
	qh = (qh + 1) % QSIZE;
}

void SSH_CBF ::
insert(const char *key){
	/*
	if (!heap.full()){
		heap.insert(key);
		return ;
	}
	*/
	uint32_t t = filter.Query((cuc *)key);
	if (t <= m){
		if ((qt + 1) % QSIZE == qh) pop();
		push(key);
		filter.Insert((cuc *)key, 1);
	} else if (t >= M){
		uint32_t l = strlen(key);
		heap.insert(key);
	} else {
		filter.Insert((cuc *)key, 1);
	}
}

void SSH_CBF ::
GetTopK(char **Ans){
	while (qh != qt) pop();
	heap.GetTopK(Ans);
}

void SSH_CBF ::
GetFreq(uint32_t limit, char **Ans){
	while (qh != qt) pop();
	if (limit > M)
		heap.GetFreq(limit - M, Ans);
	 else
		heap.GetFreq(0, Ans);
}
uint32_t SSH_CBF ::
query(const char *key){
	while (qh != qt) pop();
	return heap.query(key) + M;
}
