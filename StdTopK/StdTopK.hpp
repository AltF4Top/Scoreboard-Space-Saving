#ifndef __TDY_STDTOPK_HPP__
#define __TDY_STDTOPK_HPP__

#include "../common/forward.hpp"
/*
#include "../HashTable/HashTable.h"

class StdTopK{
public:
		HashTable table;
		uint32_t k;
		
		StdTopK(uint32_t _k);
		
		void insert(const char *key);
		void GetTopK(const char **Ans);
		
private:
		StdTopK();
		StdTopK(const StdTopK &);
		StdTopK &operator =(const StdTopK &);
};
*/

#include <string>
#include <map>

using namespace std;

class StdTopK{
public:
		map<string, uint32_t> cntr;
		uint32_t k;
		
		StdTopK(uint32_t _k);
		~StdTopK();
		
		void insert(const char *key);
		uint32_t query(const char *key) const;
		void GetTopK(char **Ans) const;
		void GetFreq(uint32_t limit, char **Ans) const;
		
private:
		StdTopK();
		StdTopK(const StdTopK &);
		StdTopK &operator =(const StdTopK &);
};

#endif
