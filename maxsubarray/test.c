#include <stdio.h>
#include "maxsubarr.h"

int main(int argc, char *argv)
{
	int a1[] = { 1, -2, 3, -4, 5, -6, 7, -8 };
	int max_left = 0;
	int max_right = 0;
	int sum = 0;

	sum = find_max_subarr(
				a1, 
				0, 
				sizeof(a1)/sizeof(a1[0]) - 1,
				&max_left,
				&max_right);

	printf("arr: ");
	for (int i = 0; i < sizeof(a1)/sizeof(a1[0]) - 1; ++i)
	{
		printf("[%d]%d ", i, a1[i]);
	}
	printf("\n");

	printf("sum:%d\tmax_left:%d\tmax_right:%d\n", sum, max_left, max_right);

	return 0;
}
