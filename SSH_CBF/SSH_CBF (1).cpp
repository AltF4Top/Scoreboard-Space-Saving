#include <cstddef>
#include <cstdio>
#include <cstring>

#include "SSH_CBF.hpp"

#include "../SpaceSavingHeap/SpaceSavingHeap.hpp"
#include "../CountingBF/CountingBF.h"

/*
#include <string>
#include <vector>

using namespace std;

SSH_CBF ::
SSH_CBF(uint32_t k, uint32_t nhf, uint32_t width, uint32_t nbit):
	heap(k), filter(nhf, width, nbit){
	threshold = width;
}

void SSH_CBF ::
insert(const string &key, uint32_t cnt){
	filter.Insert((cuc *)key.c_str(), cnt);
	
	vector<string> :: iterator p = list.end();
	for (vector<string> :: iterator i = list.begin(); i != list.end(); ++i)
	 if (*i == key){
		p = i;
		break;
	 }
	
	if (p == list.end()){
		list.push_back(key);
		p = list.end(); --p;
	}
	
	uint32_t t = filter.Query((cuc *)key.c_str());
	
	if (t >= threshold){
		heap.insert(key, t);
		filter.Delete((cuc *)key.c_str(), t);
		
		list.erase(p);
	}
}

void SSH_CBF ::
GetTopK(string *Ans){
	for (vector<string> :: iterator i = list.begin(); i != list.end(); ++i){
		uint32_t t = filter.Query((cuc *)i -> c_str());
		heap.insert(*i, t);
	}
	list.clear();
	
	heap.GetTopK(Ans);
}
*/

SSH_CBF ::
SSH_CBF(uint32_t k, uint32_t hsize, uint32_t nhf, uint32_t width, uint32_t nbit, uint32_t qlen, uint32_t _m, uint32_t _M):
	heap(k, hsize), filter(nhf, width, nbit), qh(0), qt(0), QSIZE(qlen), m(_m), M(_M){
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
		filter.Delete((cuc *)key, t);
	} else if (t >= M){
		heap.insert(key, t);
	}
	
	qh = (qh + 1) % QSIZE;
}

void SSH_CBF ::
insert(const char *key){
	uint32_t t = filter.Query((cuc *)key);
	//printf("insert: t = %d\n", t);
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
		//puts("insert: before heap");
		heap.insert(key, 1);
		//puts("insert: after heap");
	} else {
		filter.Insert((cuc *)key, 1);
	}
}

void SSH_CBF ::
GetTopK(const char **Ans){
	while (qh != qt) pop();
	heap.GetTopK(Ans);
}
