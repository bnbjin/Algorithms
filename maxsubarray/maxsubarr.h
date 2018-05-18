#ifndef __MAXSUBARR_H__
#define __MAXSUBARR_H__

int
find_max_crossing_subarr(
	int *arr, 
	int low, 
	int mid, 
	int high,
	int *max_left,
	int *max_right);

int
find_max_subarr(
	int *arr,
	int low,
	int high,
	int *max_left,
	int *max_right);

#endif // __MAXSUBARR_H__
