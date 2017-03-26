#include "bubblesort.h"
#include <iostream>

int main()
{
	int oa[] = {1, 2, 3};

	for (int i = 0; i < sizeof(oa)/sizeof(int); ++i)
	{
		std::cout << oa[i] << " ";
	}
	std::cout << std::endl;

	BubbleSort(oa, sizeof(oa)/sizeof(int));

	for (int i = 0; i < sizeof(oa)/sizeof(int); ++i)
	{
		std::cout << oa[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
