#ifndef _BLOOMFILTER_H
#define _BLOOMFILTER_H

#include "common.h"

class BloomFilter
{
public:
	BloomFilter(int w, int k);
	void Insert(cuc *str);
	bool Query(cuc *str);
	uint GetMemory() {return memoryAccess;}
	
private:
	int k;
	int width;
	HashFunction *hash;
	char *filter;
	uint memoryAccess;
};

#endif
