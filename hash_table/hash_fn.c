#include <math.h>
#include <stdlib.h>
#include "hash_fn.h"

int hash_fn_div(int k, int hashtab_len)
{
	return k % hashtab_len;
}

int hash_fn_mul(int k, int ht_len)
{
	long double A = (sqrt(5.0) - 1.0) / 2.0;
	long double res = 0;
	int p = 0;

	res = k * A * (2 << 16);

	res = fmodl(res, 2 << 16);

	p = (int)(log10(ht_len) / log10(2));

    return (int)(res / (2 << (8 - p)));
}



// m should be a power of 2
int hash_fn_mul2(int k, int m)
{
    int w = 32;
    int r = (int)(log(m) / log(2));
    int A = (int)(pow(2.0, (double)(w - r/2)) + 1.0);

    return (A * k) % (int)pow(2, w) >> (w - r);
}


int hash_fn_primclus(int k, int i, int m)
{
    return hash_fn_mul(k) % m;
}

int hash_fn_secclus(int k, int i, int m)
{
    return (hash_fn_mul(k) + 2 * i + 1 * i*i) % m;
}


int hash_fn_doubhash(int k, int i, int m)
{
    return (hash_fn_mul(k) + i * hash_fn_div(k)) % m;
}


// p should be a prime, m could be any number
// p > k > m
// k from {0, 1, ..., p-1}
int hash_fn_unvsl(int k, int m, int p)
{
    srand((unsigned int)time(NULL));
    a = rand() % p;
    b = rand() % (p-2) + 1;

    return ((a * k + b) % p) % m;
}



// m should be a prime
int hash_fn_unvsl2(int k, int m, int r)
{
    int tmp = 0;
    int arrk[r+1] = { 0 };
    int arrm[r+2] = { 0 };

    tmp = k;
    for (int i = 0; 
        i < r + 1 && tmp != 0; 
        tmp = tmp / m, ++i)
    {
        arrk[i] = k % m;
    }

    srand((unsigned int)time(NULL));
    tmp = rand() / 
    for (int i = 0; i < r + 1; ++i)
    {
        
    }

    return 
}
