#ifndef _COUNTINGBF_H
#define _COUNTINGBF_H

#include "../common/common.h"

class CountingBF
{
public:
	CountingBF(int k, int w, int b);
	void Insert(cuc *str, uint num = 1);
	void Delete(cuc *str, uint num = 1);
	uint Query(cuc *str);
	
private:
	int k;
	int width;
	int bits;
	HashFunction *hash;
	uint *filter;
};

#endif
