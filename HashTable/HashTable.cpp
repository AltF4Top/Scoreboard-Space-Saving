#include "HashTable.h"

HashTable::HashTable(int kl, int vl, int w)
{
	keyLength = kl;
	valueLength = vl;
	width = w;
	buckets = new KV*[w];
	for(int i = 0; i < w; i++)
	{
		buckets[i] = NULL;
	}
	hash = new HashFunction();
	memoryAccess = 0;
}

void HashTable::Insert(cuc *str, uint num)
{
	int index = hash->Str2Int(str, 1, strlen((const char*)str)) % width;
	if(buckets[index] == NULL)
	{
		buckets[index] = new KV(str, num);
		memoryAccess ++;
	}
	else
	{
		KV *p = buckets[index];
		memoryAccess ++;
		while(p->next != NULL)
		{
			p = p->next;
			memoryAccess ++;
		}
		p->next = new KV(str, num);
	}
}

void HashTable :: Delete(cuc *str, uint num){
	int index = hash->Str2Int(str, 1, strlen((const char *)str)) % width;
	
	for (struct KV **pp = &buckets[index], *p = *pp; p; pp = &(p -> next), p = *pp)
	 if (strcmp((const char *)p -> key, (const char *)str) == 0){
		p -> value -= num;
		
		if (p -> value == 0){
			struct KV *q = p -> next;
			delete p;
			*pp = q;
		}
		
		break;
	 }
}

uint HashTable::Query(cuc *str)
{
	int index = hash->Str2Int(str, 1, strlen((const char*)str)) % width;
	KV *p = buckets[index];
	memoryAccess ++;
	while(p != NULL)
	{
		if(strcmp((const char*)p->key, (const char*)str) == 0)
		{
			return p->value;
		}
		p = p->next;
		memoryAccess ++;
	}
	return 0;
}
