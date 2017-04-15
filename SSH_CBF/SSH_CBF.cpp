#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cmath>

#include "SSH_CBF.hpp"

#include "../SpaceSavingHeap/SpaceSavingHeap.hpp"
#include "../CountingBF/CountingBF.h"

SSH_CBF ::
SSH_CBF(uint32_t _k, uint32_t hsize, uint32_t nhf, uint32_t width, uint32_t nbit, uint32_t qlen, uint32_t _m, double phi):
	heap(_k, hsize), filter(nhf, width, nbit), qh(0), qt(0), QSIZE(qlen), m(_m),
	k(_k), baseM((uint32_t)(107283/pow(_k, 0.668))/10000000), cnt(0){
	Que = new const char *[QSIZE];
}

SSH_CBF ::
~SSH_CBF(){
	for (uint32_t i = 0; i < QSIZE; ++i)
	 if (Que[i] != NULL) delete []Que[i];
	delete []Que;
}

void SSH_CBF ::
push(const char *key){
	Que[qt] = key;
	qt = (qt + 1) % QSIZE;
}

void SSH_CBF ::
pop(){
	const char *key = Que[qh]; Que[qh] = NULL;
	
	uint32_t t = filter.Query((cuc *)key);
	if (t <= m){
		filter.Delete((cuc *)key, 1);
	} else if (t >= M){
		uint32_t l = strlen(key);
		while (t--){
			if (t){
				char *tkey = new char[l+1];
				strcpy(tkey, key);
				heap.insert(tkey);
			} else
				heap.insert(key);
		}
	} else 
		delete []key;
	
	qh = (qh + 1) % QSIZE;
}

void SSH_CBF ::
insert(const char *key){
	/*
	if (!heap.full()){
		uint32_t l = strlen(key);
		char *tkey = new char[l+1];
		strcpy(tkey, key); key = tkey;

		heap.insert(key);
		return ;
	}
	*/
	++cnt;
	M = (uint32_t)(baseM * cnt);
	
	uint32_t t = filter.Query((cuc *)key);
	if (t <= m){
		uint32_t l = strlen(key);
		char *tkey = new char[l+1];
		strcpy(tkey, key); key = tkey;
		
		if ((qt + 1) % QSIZE == qh) pop();
		push(key);
		filter.Insert((cuc *)key, 1);
	} else if (t >= M){
		uint32_t l = strlen(key);
		char *tkey = new char[l+1];
		strcpy(tkey, key); key = tkey;

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
	heap.GetFreq(limit, Ans);
}
uint32_t SSH_CBF ::
query(const char *key){
	while (qh != qt) pop();
	return heap.query(key);
}
