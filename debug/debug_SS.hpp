#ifndef __TDY_DEBUG_SS_HPP__
#define __TDY_DEBUG_SS_HPP__

#include "../common/forward.hpp"
#include "debug_SSH.hpp"

class debug_SS{
public:
	debug_SSH heap;
	
	debug_SS(uint32_t _k, uint32_t _hsize);
	~debug_SS();
	
	void insert(const char *key);
	void GetTopK(const char **Ans);
	
private:
	debug_SS();
	debug_SS(const debug_SS &);
	debug_SS &operator =(const debug_SS &);
};

#endif
