#ifndef _TDY_SPACE_SAVING_HEAP_
#define _TDY_SPACE_SAVING_HEAP_

#include "../common/common.h"
#include "../common/forward.hpp"

class SpaceSavingHeap{
public:
	struct bkt;
	struct node;
	
	struct bkt{
		uint32_t cnt;
		
		struct bkt *prv, **pnxt;
		struct node *first;
	};
	
	struct node{
		const char *key;
		
		struct bkt *f;
		struct node *bprv, *bnxt;
		struct node *hnxt, **hpprv;
	};
	
	const uint32_t NHASHBKT;
	struct node **hash;
	HashFunction hashfunc;
	
	struct node *node_buf;
	
	struct bkt *bkt_buf;
	struct bkt *bkt_free_list;
	struct bkt *least;
	
	const uint32_t m;
	uint32_t n;
	
	uint32_t k;
	
	SpaceSavingHeap(uint32_t _k, uint32_t _hsize);
	~SpaceSavingHeap();
	void insert(const char *key);
	bool full() const;
	void GetTopK(char **Ans) const;
	void GetFreq(uint32_t limit, char **Ans) const;
	uint32_t query(const char *key) const;

private:
	SpaceSavingHeap();
	SpaceSavingHeap(const SpaceSavingHeap &);
	SpaceSavingHeap &operator =(const SpaceSavingHeap &);
	
	void surface(uint32_t x);
	void sink(uint32_t x);
};
#endif
