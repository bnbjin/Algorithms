#ifndef __HASH_FN_H__
#define __HASH_FN_H__

// HASH_LEN_DIV (prime_near(2 >> 10)
// HASH_LEN_MUL (2 << 10)

int hash_fn_div(int k, int hashtab_len);

int hash_fn_mul(int k, int ht_len);

// m should be a power of 2
int hash_fn_mul2(int k, int m);

void hash_fn_unvsl_init(int p);

// universal hashing
// p should be a prime, m could be any number
// p > k > m
// k from {0, 1, ..., p-1}
int hash_fn_unvsl(int k, int m);

// universal hashing
// m should be a prime
int hash_fn_unvsl2(int k, int m, int p);

// primary clustering
int hash_fn_primclus(int k, int i, int m);

// secondary clusering
int hash_fn_secclus(int k, int i, int m);

// double hashing
int hash_fn_doubhash(int k, int i, int m);

#endif // __HASH_FN_H__
