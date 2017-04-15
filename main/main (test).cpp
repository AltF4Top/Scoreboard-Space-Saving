#include "../SpaceSaving/SpaceSaving.hpp"
#include "../debug/debug_SS.hpp"
#include "../StdTopK/StdTopK.hpp"

#include "config.hpp"

#include <cstdio>
#include <cstring>

#if (SSH_HEAPSIZE >= K)

static SS ss(
	K, SSH_HEAPSIZE
);

static debug_SS dss(
	K, SSH_HEAPSIZE
);

static StdTopK stk(K);

static char key[30];
static const char *dssAns[K], *ssAns[K], *stkAns[K];

int main(){
	FILE *inf = fopen("/home/lenovo/Documents/paper/data/u2", "rb");
	int t = 0;
	while (fread(key, sizeof(char), 13, inf)){
//		dss.insert(key);
		ss.insert(key);
		stk.insert(key);
		
		if (++t % 1000000 == 0) printf("t = %d\n", t);
		//if (t == 2000) break;
	}
//	dss.GetTopK(dssAns);
	ss.GetTopK(ssAns);
	stk.GetTopK(stkAns);
/*	
	for (uint32_t i = 0; i < K; ++i)
		if (strcmp(dssAns[i], ssAns[i]) != 0)
			puts("!!!!WARNING!!!!!");
*/	
	uint32_t cnt = 0;
	for (uint32_t i = 0; i < K; ++i)
	 if (ssAns[i]){
		for (uint32_t j = 0; j < K; ++j)
	     if (stkAns[j] && strcmp(ssAns[i], stkAns[j]) == 0){
			++cnt;
			break;
		}
	}
	printf("ss rate = %.10lf\n", (double)cnt / K);
	
	return 0;
}

#endif

