#include "StdTopK.hpp"

#include "../common/forward.hpp"

#include <cstdio>
#include <cstring>

#include <algorithm>
#include <string>
#include <map>

using namespace std;

/*
StdTopK ::
StdTopK(uint32_t _k): k(_k), table(0, 0, 100){
}

void StdTopK ::
insert(const char *key){
	table.Insert((const unsigned char *)key, 1);
}

void StdTopK :: 
GetTopK(const char **Ans){
	for (uint32_t i = 0; i < table.width; ++i){
		struct KV *t = NULL;
		for (struct KV *p = table.buckets[i]; p; p = p -> next)
		 if (t == NULL || t -> value < p -> value)
			t = p;
		Ans[i] = (const char *)t -> key;
		t -> key = NULL; t -> value = 0;	
	}
}
*/

StdTopK ::
StdTopK(uint32_t _k): k(_k){
}

StdTopK ::
~StdTopK(){
}

void StdTopK ::
insert(const char *key){
	string key_s(key);
	
	map<string, uint32_t> :: iterator p = cntr.find(key_s);
	if (p != cntr.end()){
		++p -> second;
	} else {
		cntr.insert(pair<string, uint32_t>(key_s, 1));
	}
}

uint32_t StdTopK ::
query(const char *key) const{
	string key_s(key);
	map<string, uint32_t> :: const_iterator p = cntr.find(key_s);
	if (p != cntr.end())
		return p -> second;
	 else
		return 0;
}

static bool cmp(const pair<string, uint32_t> &x, const pair<string, uint32_t> &y){
	return x.second > y.second;
}

void StdTopK ::
GetTopK(char **Ans) const{
	uint32_t s = cntr.size();
	pair<string, uint32_t> *t = new pair<string, uint32_t>[s];
	uint32_t i = 0; map<string, uint32_t> :: const_iterator p;
	for (i = 0, p = cntr.begin(); i < s; ++i, ++p)
		t[i] = *p;
	
	sort(t, t + s, cmp);
	for (i = 0; i < k; ++i){
		uint32_t s = t[i].first.length();
		char *key = new char[s+1];
		memcpy(key, t[i].first.c_str(), s);
		key[s] = 0;
		Ans[i] = key;
	}
	delete []t;
}

void StdTopK ::
GetFreq(uint32_t limit, char **Ans) const{
	uint32_t i = 0;
	map<string, uint32_t> :: const_iterator p;
	for (p = cntr.begin(); p != cntr.end(); ++p)
	 if (p -> second >= limit){
		 uint32_t s = p -> first.length();
		 char *key = new char[s+1];
		 memcpy(key, p -> first.c_str(), s);
		 key[s] = 0;
		 Ans[i++] = key;
	 }
	Ans[i] = 0;
}
