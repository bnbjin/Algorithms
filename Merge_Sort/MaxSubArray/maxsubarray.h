#ifndef __MAX_SUB_ARRAY_H__
#define __MAX_SUB_ARRAY_H__


struct SUBARRAY_INFO
{
	unsigned int	low;
	unsigned int 	high;
	int 			sum;
};


template <class T>
SUBARRAY_INFO* FindMaxSubArray(
	SUBARRAY_INFO *_pSAInfo,
	T *_pSourceArray, 
	unsigned int _iLow,
	unsigned int _iHigh);


template <class T>
SUBARRAY_INFO* FindMaxCrossingSubArray(
	SUBARRAY_INFO *_pSAInfo,
	T *_pSourceArray,
	unsigned int _iLow,
	unsigned int _iMiddle,
	unsigned int _iHigh);


#include "maxsubarray.cpp"

#endif // __MAX_SUB_ARRAY_H__
