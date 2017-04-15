#ifndef __TDY_SSH_HT_HPP__
#define __TDY_SSH_HT_HPP__

#include "../HashTable/HashTable.h"
#include "../SpaceSavingHeap/SpaceSavingHeap.hpp"

#include <string>
using namespace std;

class SSH_HT{
public:
	SpaceSavingHeap heap;
	HashTable table;
	
	uint32_t threshold;
	
	SSH_HT(uint32_t h, uint32_t w);
	
	void insert(const string &key, uint32_t cnt);
	void GetTopK(string *Ans);

private:
	SSH_HT();
	SSH_HT(const SSH_HT &);
	SSH_HT &operator =(const SSH_HT &);
};

#endif
