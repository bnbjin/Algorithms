#include "mergesort.h"
#include <iostream>

int main()
{
	int sa[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int wa[sizeof(sa)/sizeof(int)] = {0};

	for (int i = 0; i < sizeof(sa)/sizeof(int); ++i)
	{
		std::cout << sa[i] << " ";
	}
	std::cout << std::endl;

	MergeSort(sa, wa, 0, sizeof(sa)/sizeof(int) - 1);

	for (int i = 0; i < sizeof(sa)/sizeof(int); ++i)
	{
		std::cout << sa[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
