#ifndef _TDY_SPACE_SAVING_HEAP_
#define _TDY_SPACE_SAVING_HEAP_

#include "../common/common.h"
#include "../common/forward.hpp"

class SpaceSavingHeap{
public:
	struct node{
		const char *key;
		uint32_t cnt;
		
		node *next;
		node **pprev;
	};
	
	static const uint32_t HashRange = 128;
	struct node *hash[HashRange];
	HashFunction hashfunc;
	
	struct node *heap;
	const uint32_t hsize;
	uint32_t hn;
	
	uint32_t k;
	
	SpaceSavingHeap(uint32_t _k, uint32_t _hsize);
	~SpaceSavingHeap();
	void insert(const char *key, uint32_t cnt);
	void GetTopK(const char **Ans);

private:
	SpaceSavingHeap();
	SpaceSavingHeap(const SpaceSavingHeap &);
	SpaceSavingHeap &operator =(const SpaceSavingHeap &);
	
	void surface(uint32_t x);
	void sink(uint32_t x);
};
#endif
