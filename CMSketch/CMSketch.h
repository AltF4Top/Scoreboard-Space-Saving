#ifndef _CMSKETCH_H
#define _CMSKETCH_H

#include "common.h"

class CMSketch
{
public:
	CMSketch(int d, int w, int b);
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
