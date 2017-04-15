#include "CUSketch.h"
#include <string.h>

CUSketch::CUSketch(int d, int w, int b)
{
	depth = d;
	width = w;
	bits = b;
	hash = new HashFunction();
	sketch = new uint*[d];
	for(int i = 0; i < d; i++)
	{
		sketch[i] = new uint[w];
	}
	MAXV = (1 << b) - 1;
}

void CUSketch::Insert(cuc *str, uint num)
{
	int level = 0;
	uint MIN = MAXV;
	for(int i = 0; i < depth; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width;
		memoryAccess ++;
		if(sketch[i][index] < MIN)
		{
			MIN = sketch[i][index];
			level = i;
		}
	}
	uint final = MIN + num;
	if(final > MAXV) final = MAXV;
	for(int i = 0; i < depth; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width;
		//memoryAccess ++;
		if(sketch[i][index] < final)
		{
			sketch[i][index] = final;
		}
	}
}

uint CUSketch::Query(cuc *str)
{
	uint MIN = MAXV;
	for(int i = 0; i < depth; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width;
		memoryAccess ++;
		if(sketch[i][index] < MIN)
		{
			MIN = sketch[i][index];
		}
	}
	return MIN;
}

void CUSketch::Remove(cuc *str, uint num)
{
	
}
