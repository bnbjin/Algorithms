#include "hash_fn.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


static int a = 0;
static int b = 0;
static int sg_p = 0;


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



int hash_fn_mul2(int k, int m)
{
    int w = 16;
    int r = (int)(log(m) / log(2));
    int A = (int)(pow(2.0, (double)(w - r/2)) + 1.0);

    return (A * k) % (int)pow(2, w) >> (w - r);
}


int hash_fn_primclus(int k, int i, int m)
{
    return hash_fn_mul(k, m) % m;
}

int hash_fn_secclus(int k, int i, int m)
{
    return (hash_fn_mul(k, m) + 2 * i + 1 * i*i) % m;
}


int hash_fn_doubhash(int k, int i, int m)
{
    return (hash_fn_mul(k, m) + i * hash_fn_div(k, m)) % m;
}


void hash_fn_unvsl_init(int p)
{
    srand((unsigned int)time(NULL));
    a = rand() % p;
    b = rand() % (p - 1) + 1;
    sg_p = p;
}


int hash_fn_unvsl(int k, int m)
{
    return ((a * k + b) % sg_p) % m;
}


int hash_fn_unvsl2(int k, int m, int r)
{
    int tmp = 0;
    int arrk[r+1];
    int arrm[r+2];

    memset(arrk, 0, sizeof(int) * (r+1));
    memset(arrm, 0, sizeof(int) * (r+2));

    tmp = k;
    for (int i = 0; 
        i < r + 1 && tmp != 0; 
        tmp = tmp / m, ++i)
    {
        arrk[i] = k % m;
    }

    srand((unsigned int)time(NULL));
    /*
    tmp = rand() / 
    for (int i = 0; i < r + 1; ++i)
    {
        
    }
    */

    return -1;
}
