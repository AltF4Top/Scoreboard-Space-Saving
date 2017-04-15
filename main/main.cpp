#include "../SpaceSaving/SpaceSaving.hpp"
#include "../SSH_CBF/SSH_CBF.hpp"
#include "../StdTopK/StdTopK.hpp"

#include "config.hpp"

#include <cstdio>
#include <cstring>
#include <cmath>

/*
#if ((SSH_HEAPSIZE >= K) && (SS_HEAPSIZE >= K))
#if (SSH_CBF_m <= SSH_CBF_M)
#if (SSH_CBF_m >= 0)
#if (SSH_CBF_M < 1 << CBF_NBITS)
*/


static SSH_CBF ssh(
	K, SSH_HEAPSIZE, CBF_NHF, CBF_NCNTR, CBF_NBITS,
	SSH_CBF_QLEN, SSH_CBF_m, phi
);

static SS ss(
	K, SS_HEAPSIZE
);

static StdTopK stk(K);

static char key[50];
static char **sshAns, **ssAns, **stkAns;
static double ssh_rate, ss_rate;

int main(){
	printf("%d\n", K);
	FILE *inf = fopen("/home/lenovo/Documents/laboratery/CBFQueSS/data/u2", "rb");
	int t = 0;
	while (fread(key, sizeof(char), 13, inf)){
		ssh.insert(key);
		ss.insert(key);
		stk.insert(key);
		if (++t % 1000000 == 0) printf("t = %d\n", t);
		//if (t == 1000) break;
	}
	fclose(inf);
	
	sshAns = new char *[K+1];
	ssAns = new char *[K+1];
	stkAns = new char *[K+1];

#if defined(TOPK)
	ssh.GetTopK(sshAns);
	ss.GetTopK(ssAns);
	stk.GetTopK(stkAns);
	
	uint32_t sscnt, sshcnt, stkcnt;
	sscnt = sshcnt = stkcnt = K;
#elif defined(FREQ)
	uint32_t freq = (uint32_t)(phi * t);
	printf("%d\n", freq);
	ssh.GetFreq(freq, sshAns);
	ss.GetFreq(freq, ssAns);
	stk.GetFreq(freq, stkAns);
	
	uint32_t sshcnt = 0;
	while (sshAns[sshcnt++]); --sshcnt;
	uint32_t sscnt = 0;
	while (ssAns[sscnt++]); --sscnt;
	uint32_t stkcnt = 0;
	while (stkAns[stkcnt++]); --stkcnt;
	
	printf("%d %d %d\n", sshcnt, sscnt, stkcnt);
#endif

#if defined(PR)
	uint32_t cnt = 0;
	for (uint32_t i = 0; i < sshcnt; ++i)
	 if (sshAns[i]){
		for (uint32_t j = 0; j < stkcnt; ++j)
		 if (stkAns[j] && strcmp(sshAns[i], stkAns[j]) == 0){
			++cnt;
			break;
		 }
	 }
	printf("%d %d\n", cnt, sshcnt);
	ssh_rate = (double)cnt / sshcnt;
	
	cnt = 0;
	for (uint32_t i = 0; i < sscnt; ++i)
	 if (ssAns[i]){
		for (uint32_t j = 0; j < stkcnt; ++j)
		 if (stkAns[j] && strcmp(ssAns[i], stkAns[j]) == 0){
			++cnt;
			break;
		 }
	 }
	printf("%d %d\n", cnt, sscnt);
	ss_rate = (double)cnt / sscnt;
	

#elif defined(RR)
	
	uint32_t cnt = 0;
	for (uint32_t i = 0; i < stkcnt; ++i)
	 if (stkAns[i]){
		 for (uint32_t j = 0; j < sshcnt; ++j)
		  if (sshAns[j] && strcmp(sshAns[j], stkAns[i]) == 0){
			  ++cnt;
			  break;
		  }
	 }
	 
	ssh_rate = (double)cnt / stkcnt;
	 
	cnt = 0;
	for (uint32_t i = 0; i < stkcnt; ++i)
	 if (stkAns[i]){
		 for (uint32_t j = 0; j < sscnt; ++j)
		  if (ssAns[j] && strcmp(ssAns[j], stkAns[i]) == 0){
			  ++cnt;
			  break;
		  }
	 }
	ss_rate = (double)cnt / stkcnt;
#endif
	
	//FILE *outf = fopen("/home/lenovo/Documents/laboratery/CBFQueSS/result/pr_freq_real_phi.txt", "a");
	FILE *outf = stdout;
	fprintf(outf, "%.8lf,%.10lf,%.10lf\n", phi, ssh_rate, ss_rate);
	fclose(outf);
	
	return 0;
}
/*
#endif
#endif
#endif
#endif
*/
