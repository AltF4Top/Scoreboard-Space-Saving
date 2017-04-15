#include "BloomFilter.h"
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

BloomFilter::BloomFilter(int w, int k)
{
	this->k = k;
	width = w;
	hash = new HashFunction();
	filter = new char[(w+7)/8];
	memset(filter, 0, sizeof(char)*(w+7)/8);
	memoryAccess = 0;
}

void BloomFilter::Insert(cuc *str)
{
	for(int i = 0; i < k; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width; 
		int offset = index % 8;
		index = index / 8;
		filter[index] |= (1 << offset);
		memoryAccess ++;
	} 
}

bool BloomFilter::Query(cuc *str)
{
	for(int i = 0; i < k; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width; 
		int offset = index % 8;
		index = index / 8;
		memoryAccess ++;
		if(((filter[index] >> offset) & 1) == 0)
		{
			return false;
		}
	} 
	return true;
}
