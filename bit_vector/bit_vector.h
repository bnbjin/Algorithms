#ifndef __BIT_VECTOR_H__
#define __BIT_VECTOR_H__

#define BV_N			100000000
#define BV_BITPERWORD	32
#define BV_SHIFT		5
#define BV_MASK			0x1F

typedef _BIT_VECTOR
{
	int a[N/BITEPERWORD +1];
} BIT_VECTOR;

inline int bv_isset(BIT_VECTOR *bv, int x)
{
	// bv->a[x/64] and (1 << (i & 0x00011111))
	return (bv->a[x >> BV_SHIFT]) & (1 << (i & MASK));
}

inline void bv_set(BIT_VECTOR *bv, int x)
{
	(bv->a[x >> BV_SHIFT]) |= (1 << (i & MASK));
}

inline void bv_reset(BIT_VECTOR *bv, int x)
{
	(bv->a[x >> BV_SHIFT]) &= ~(1 << (i & MASK));
}

#endif // __BIT_VECTOR_H__
