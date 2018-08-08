#include <math.h>
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
