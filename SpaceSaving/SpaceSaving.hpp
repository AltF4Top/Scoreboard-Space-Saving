#ifndef __TDY_SS_HPP__
#define __TDY_SS_HPP__

#include "../common/forward.hpp"
#include "../SpaceSavingHeap/SpaceSavingHeap.hpp"

class SS{
public:
	SpaceSavingHeap heap;
	
	SS(uint32_t _k, uint32_t _hsize);
	~SS();
	
	void insert(const char *key);
	void GetTopK(char **Ans) const;
	void GetFreq(uint32_t limit, char **Ans) const;
	uint32_t query(const char *key) const;
	
private:
	SS();
	SS(const SS &);
	SS &operator =(const SS &);
};

#endif
