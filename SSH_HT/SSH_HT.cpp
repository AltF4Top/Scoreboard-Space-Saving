#include "SSH_HT.hpp"

#include <string>

using namespace std;

SSH_HT ::
SSH_HT(uint32_t k, uint32_t w): heap(k), table(0, 0, w){
	threshold = w;
}

void SSH_HT ::
insert(const string &key, uint32_t cnt){
	table.Insert((cuc *)key.c_str(), cnt);
	
	uint32_t t = table.Query((cuc *)key.c_str());
	if (t >= threshold){
		table.Delete((cuc *)key.c_str(), cnt);
		heap.insert(key, cnt);
	}
}

void SSH_HT ::
GetTopK(string *Ans){
	for (int i = 0; i < table.width; ++i)
	 for (struct KV *p = table.buckets[i], *q; p; p = q){
		heap.insert(string((const char *)p -> key), p -> value);
		q = p -> next; delete p;
	 }
	
	heap.GetTopK(Ans);	
}
