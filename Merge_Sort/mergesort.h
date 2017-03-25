#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__


template <class T>
void MergeSort(
	T *_SourceArray, 
	T *_WorkArray,
	unsigned int _iStart,
	unsigned int _iEnd);


template <class T>
void Merge(
	T *_SourceArray,
	T *_WorkArray,
	unsigned int _iStart,
	unsigned int _iMiddle,
	unsigned int _iEnd);


#include "mergesort.cpp"

#endif // __MERGE_SORT_H__
