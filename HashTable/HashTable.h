#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "../common/common.h"
#include <string.h>

struct KV
{
	KV(cuc *k, uint v)
	{
		int len = strlen((const char*)k) + 1;
		key = new unsigned char[len];
		strcpy((char*)key, (const char*)k);
		value = v;
		next = NULL;
	}
	unsigned char *key;
	uint value;	
	KV *next;
};

class HashTable
{
public:
	HashTable(int kl, int vl, int w);
	void Insert(cuc *str, uint num = 1);
	void Delete(cuc *str, uint num = 1);
	uint Query(cuc *str);
	uint GetMemory() {return memoryAccess;}
	
public:
	int keyLength;
	int valueLength;
	int width;
	KV **buckets;
	HashFunction *hash;
	uint memoryAccess;
};

#endif
