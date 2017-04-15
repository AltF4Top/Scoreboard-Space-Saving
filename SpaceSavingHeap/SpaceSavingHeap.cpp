#include "SpaceSavingHeap.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <new>

SpaceSavingHeap ::
SpaceSavingHeap(uint32_t _k, uint32_t _m): k(_k), n(0), m(_m), NHASHBKT(2 * _k), least(NULL){
	node_buf = new struct node[m];
	memset(node_buf, 0, m * sizeof(struct node));
	
	bkt_buf = new struct bkt[m];
	bkt_free_list = NULL;
	for (uint32_t i = 0; i < m; ++i){
		bkt_buf[i].prv = bkt_free_list;
		bkt_free_list = &bkt_buf[i];
	}
	
	hash = new struct node *[NHASHBKT];
	memset(hash, 0, NHASHBKT * sizeof(struct node *));
}

SpaceSavingHeap ::
~SpaceSavingHeap(){
	for (uint32_t i = 0; i < m; ++i)
		if (node_buf[i].key)
			delete []node_buf[i].key;
	delete []node_buf;
	delete []bkt_buf;
	delete []hash;
}

void SpaceSavingHeap ::
insert(const char *key){
/*
	static uint32_t T_T = 0;

	uint32_t check = 0;

	for (struct bkt *ib = least; ib; ib = ib -> prv){
		struct node *t = ib -> first;
		if (T_T == 6237 || T_T == 6238) printf("%3d: ", ib -> cnt);
		do {
			check += ib -> cnt;
			if (T_T == 6237 || T_T == 6238) printf("%02x%02x%02x ", (unsigned char)t->key[0], (unsigned char)t->key[1], (unsigned char)t->key[2]);
			
			t = t -> bnxt;
		} while (t != ib -> first);
		if (T_T == 6237 || T_T == 6238) putchar('\n');
		if (ib == ib -> prv){
			puts("IB WARNING!");
			exit(0);
		}
	}
	if (check != T_T)
		if (T_T == 6237 || T_T == 6238) printf("WARNING!: check: %d, T_T: %d\n", check, T_T);

	check = 0;
	for (uint32_t i = 0; i < NHASHBKT; ++i){
//		if (T_T == 1378 || T_T == 1379) printf("i = %d:", i);
		for (struct node *t = hash[i]; t; t = t -> hnxt){
			int index = hashfunc.Str2Int((cuc *)t -> key, 1, strlen(t -> key)) % NHASHBKT;
			if (index != i) puts("HASH WARNING!");
			check += t -> f -> cnt;
//			if (T_T == 1378 || T_T == 1379) printf("%02x%02x%02x ", (unsigned char)t->key[0],(unsigned char)t->key[1],(unsigned char)t->key[2]);
		}
//		if (T_T == 1378 || T_T == 1379) putchar('\n');
	}
	
	if (check != T_T)
		printf("WARNING!!!!!: check: %d, T_T: %d\n", check, T_T);

	++T_T;
*/
	//printf("insert: %02x%02x%02x\n", (unsigned char)key[0],(unsigned char)key[1],(unsigned char)key[2]);

	int index = hashfunc.Str2Int((cuc *)key, 1, strlen(key)) % NHASHBKT;
	
	struct node *p, **pp;
	for (pp = &hash[index], p = *pp; p; pp = &p -> hnxt, p = *pp)
	 if (strcmp(p -> key, key) == 0)
	  break;
	//puts("1st");
	if (p == NULL){
		
		if (n < m){
			p = &node_buf[n++];
			p -> key = key;
			p -> hnxt = NULL;
			p -> hpprv = pp; *pp = p;
			
			if (!least || least -> cnt != 1){
				struct bkt *b = bkt_free_list;
				bkt_free_list = bkt_free_list -> prv;
				
				b -> cnt = 1;
				b -> prv = least;
				if (b -> prv)
					b -> prv -> pnxt = &b -> prv;
				least = b;
				
				b -> pnxt = &least;
				b -> first = p;
				
				p -> bnxt = p -> bprv = p;
				p -> f = b;
			} else {
				struct node *q = least -> first;
				
				p -> bprv = q -> bprv;
				p -> bprv -> bnxt = p;
				p -> bnxt = q; q -> bprv = p;
				
				p -> f = least;
			}
			return ;
		} else {
			p = least -> first; delete []p -> key;
			p -> key = key;
			
			if (pp != &p -> hnxt){
				if (p -> hnxt)
					p -> hnxt -> hpprv = p -> hpprv;
				*(p -> hpprv) = p -> hnxt;
				
				*pp = p; p -> hpprv = pp;
			}
			p -> hnxt = NULL;
		}
	} else {
		delete []key;
	}
	//puts("half");
	struct bkt *b = p -> f;
	struct bkt **pb = &b -> prv;
	
	uint32_t cnt = b -> cnt + 1;
	
	if (p -> bnxt != p){
		if (p == b -> first)
			b -> first = p -> bnxt;
		p -> bnxt -> bprv = p -> bprv;
		p -> bprv -> bnxt = p -> bnxt;
	} else {
		pb = b -> pnxt; *pb = b -> prv;
		if (b -> prv)
			b -> prv -> pnxt = b -> pnxt;
		
		b -> prv = bkt_free_list;
		bkt_free_list = b;
	}
	//puts("3rd");
	if (*pb && (*pb) -> cnt == cnt){
		b = *pb;
		struct node *q = b -> first;
		p -> bprv = q -> bprv;
		p -> bprv -> bnxt = p;
		q -> bprv = p;
		p -> bnxt = q;
		
		p -> f = b;
	} else {
		b = bkt_free_list;
		bkt_free_list = bkt_free_list -> prv;
		
		b -> cnt = cnt;
		
		b -> prv = *pb;
		if (*pb)
			b -> prv -> pnxt = &b -> prv;
		
		b -> pnxt = pb; *pb = b;
		b -> first = p;
		
		p -> bprv = p -> bnxt = p;
		p -> f = b;
	}
}

bool SpaceSavingHeap ::
full() const{
	return n == m;
}

void SpaceSavingHeap ::
GetTopK(char **Ans) const{
	struct node *t = least -> first;
	for (uint32_t i = k; i < m; ++i)
		if (t -> bnxt != t -> f -> first)
			t = t -> bnxt;
		else {
			struct bkt *b = t -> f -> prv;
			if (b)
				t = b -> first;
			 else
				break;
		}

	for (uint32_t i = 0; i < k; ++i){
		uint32_t l = strlen(t -> key);
		char *tkey = new char[l+1]; strcpy(tkey, t -> key);
		Ans[i] = tkey;
		if (t -> bnxt != t -> f -> first)
			t = t -> bnxt;
		else {
			struct bkt *b = t -> f -> prv;
			if (b)
				t = b -> first;
			 else
				break;
		}
	}
}

void SpaceSavingHeap ::
GetFreq(uint32_t limit, char **Ans) const{
	uint32_t i = 0;
	struct bkt *b;
	for (b = least; b && b -> cnt < limit; b = b -> prv)
		(void)0;
	
	for (; b; b = b -> prv){
		struct node *p = b -> first;
		do {
			uint32_t l = strlen(p -> key);
			char *tkey = new char[l+1]; strcpy(tkey, p -> key);
			Ans[i++] = tkey;
			p = p -> bnxt;
		} while (p != b -> first);
	}
	Ans[i] = 0;
/*
	puts("FREQ");
	for (b = least; b; b = b -> prv){
		struct node *p = b -> first;
		do {
			printf("%d ", b -> cnt);
			p = p -> bnxt;
		} while (p != b -> first);
		putchar('\n');
	}
*/
}

uint32_t SpaceSavingHeap ::
query(const char *key) const{
	int index = hashfunc.Str2Int((cuc *)key, 1, strlen(key)) % NHASHBKT;
	
	for (struct node *p = hash[index]; p; p = p -> hnxt)
	 if (strcmp(key, p -> key) == 0)
		return p -> f -> cnt;
			
	return 0;
}
