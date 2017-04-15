#include "CMSketch.h"
#include <string.h>

CMSketch::CMSketch(int d, int w, int b)
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

void CMSketch::Insert(cuc *str, uint num)
{
	for(int i = 0; i < depth; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width;
		memoryAccess ++;
		if(sketch[i][index] + num < MAXV)
		{
			sketch[i][index] += num;
		}
		else
		{
			sketch[i][index] = MAXV;
		}
	}
}

void CMSketch::Remove(cuc *str, uint num)
{
	for(int i = 0; i < depth; i++)
	{
		int index = hash->Str2Int(str, i, strlen((const char*)str)) % width;
		memoryAccess ++;
		if(sketch[i][index] >= num)
		{
			sketch[i][index] -= num;
		}
		else
		{
			sketch[i][index] = 0;
		}
	}
}

uint CMSketch::Query(cuc *str)
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
