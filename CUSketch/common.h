#ifndef _COMMON_H
#define _COMMON_H

#define FALSE 0
#define TRUE 1
#define STR_LEN 13
#define INF_SAC (40000)
#define INF_SHORT ((1<<16)-1)
#define min(x, y) (x<y?x:y)

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint; 
typedef long long unsigned int ull;
typedef const unsigned char cuc;
typedef unsigned int(*funPtr)(const unsigned char*, unsigned int);

// uint BOB1(cuc *str, uint len);
// uint BOB2(cuc *str, uint len);
// uint BOB3(cuc *str, uint len);
// uint BOB4(cuc *str, uint len);
// uint RSHash(cuc *str, uint len);
// uint JSHash(cuc *str, uint len);
// uint PJWHash(cuc* str, uint len);
// uint ELFHash(cuc *str, uint len);
// uint BKDRHash(cuc *str, uint len);
// uint SDBMHash(cuc*str, uint len);
// uint DJBHash(cuc* str, uint len);
// uint DEKHash(cuc *str, uint len);
// uint APHash(cuc *str, uint len);
// uint DJBHash(cuc *str, uint len);

struct HashFunction{
	HashFunction();
	uint Str2Int(cuc* str, uint hidx, uint len = STR_LEN);
	funPtr hash_function[14];
};

#endif
