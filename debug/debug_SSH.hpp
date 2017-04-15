#ifndef _TDY_DEBUG_SPACE_SAVING_HEAP_
#define _TDY_DEBUG_SPACE_SAVING_HEAP_

#include "../common/common.h"
#include "../common/forward.hpp"

class debug_SSH{
public:
	struct node{
		const char *key;
		uint32_t cnt;
	};
	
	struct node *heap;
	const uint32_t hsize;
	uint32_t hn;
	
	uint32_t k;
	
	debug_SSH(uint32_t _k, uint32_t _hsize);
	~debug_SSH();
	void insert(const char *key, uint32_t cnt);
	void GetTopK(const char **Ans);

private:
	debug_SSH();
	debug_SSH(const debug_SSH &);
	debug_SSH &operator =(const debug_SSH &);
	
	void surface(uint32_t x);
	void sink(uint32_t x);
};
#endif
