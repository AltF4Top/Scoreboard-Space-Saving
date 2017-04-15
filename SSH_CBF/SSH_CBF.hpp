#ifndef __TDY_SSH_CBF_HPP__
#define __TDY_SSH_CBF_HPP__

#include "../SpaceSavingHeap/SpaceSavingHeap.hpp"
#include "../CountingBF/CountingBF.h"

/*
#include <vector>
#include <string>

using namespace std;

class SSH_CBF{
public:
	SpaceSavingHeap heap;
	CountingBF filter;
	vector<string> list;
	
	uint32_t threshold;
	
	SSH_CBF(uint32_t k, uint32_t nhf, uint32_t width, uint32_t nbit);

	void insert(const string &key, uint32_t cnt);
	void GetTopK(string *Ans);
	
private:
	SSH_CBF();
	SSH_CBF(const SSH_CBF &);
	SSH_CBF &operator =(const SSH_CBF &);
};
*/

class SSH_CBF{
public:
	SpaceSavingHeap heap;
	CountingBF filter;
	const char **Que;
	uint32_t qh, qt;
	const uint32_t QSIZE;
	uint32_t m, M;
	const uint32_t k;
	const double baseM;
	uint32_t cnt;
	
	uint32_t threshold;
	
	SSH_CBF(uint32_t k, uint32_t hsize, uint32_t nhf, uint32_t width, uint32_t nbit, uint32_t qlen, uint32_t _m, double phi);
	~SSH_CBF();
	
	void insert(const char *key);
	void GetTopK(char **Ans);
	void GetFreq(uint32_t limit, char **Ans);
	uint32_t query(const char *key);
	
private:
	SSH_CBF();
	SSH_CBF(const SSH_CBF &);
	SSH_CBF &operator =(const SSH_CBF &);
	
	void push(const char *key);
	void pop();
};

#endif
