#ifndef __HASH_FN_H__
#define __HASH_FN_H__

// HASH_LEN_DIV (prime_near(2 >> 10)
// HASH_LEN_MUL (2 << 10)

int hash_fn_div(int k, int hashtab_len);

int hash_fn_mul(int k, int ht_len);

// primary clustering
int hash_fn_primclus(int k, int i, int m);

// secondary clusering
int hash_fn_secclus(int k, int i, int m);

// double hashing
int hash_fn_doubhash(int k, int i, int m);

#endif // __HASH_FN_H__
