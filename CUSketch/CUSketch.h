#ifndef _CUSKETCH_H
#define _CUSKETCH_H

#include "common.h"

class CUSketch
{
public:
	CUSketch(int d, int w, int b);
	void Insert(cuc *str, uint num);
	void Remove(cuc *str, uint num);
	uint Query(cuc *str);
	
private:
	int depth;
	int width;
	int bits;
	HashFunction *hash;
	uint **sketch;
	uint MAXV;
};

#endif
