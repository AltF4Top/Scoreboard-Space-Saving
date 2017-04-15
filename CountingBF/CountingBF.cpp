#include "CountingBF.h"
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

CountingBF::CountingBF(int k, int w, int b)
{
	this->k = k;
	width = w;
	bits = b;
	hash = new HashFunction();
	filter = new uint[w];
	memset(filter, 0, sizeof(uint)*w);
}

void CountingBF::Insert(cuc *str, uint num)
{
	for(int i = 0; i < k; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width;
		if(filter[index] + num < (1 << bits) - 1)
		{
			filter[index] += num;
		}
		else
		{
			filter[index] = (1 << bits) - 1;
		}
	} 
}

void CountingBF :: Delete(cuc *str, uint num){
	for (int i = 0; i < k; ++i){
		int index = hash -> Str2Int(str, i, strlen((const char *)str)) % width;
		
		if (filter[index] >= num)
			filter[index] -= num;
		 else
			filter[index] = 0;
	}
}

uint CountingBF::Query(cuc *str)
{
	uint MIN = (1 << bits) - 1;
	for(int i = 0; i < k; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width; 
		MIN = MIN > filter[index] ? filter[index] : MIN;
	} 
	return MIN;
}
