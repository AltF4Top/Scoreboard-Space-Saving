#ifndef _TDY_SPACE_SAVING_HEAP_
#define _TDY_SPACE_SAVING_HEAP_

#include "../common/common.h"
#include "../common/forward.hpp"

#include <string>

using namespace std;

class SpaceSavingHeap{
public:
	struct heap_node {
		string *key;
		uint32_t cnt;
	};
		
	heap_node *heap;
	static const uint32_t HEAPSIZESCALE = 2;
	const uint32_t HEAPSIZE;
	uint32_t hn;
	
	uint32_t k;
	
	SpaceSavingHeap(uint32_t _k);
	~SpaceSavingHeap();
	void insert(const string &key, uint32_t cnt);
	void GetTopK(string *Ans);
	
private:
	SpaceSavingHeap();
	SpaceSavingHeap(const SpaceSavingHeap &);
	SpaceSavingHeap &operator =(const SpaceSavingHeap &);
	
	void surface(uint32_t x);
	void sink(uint32_t x);
};

#endif
