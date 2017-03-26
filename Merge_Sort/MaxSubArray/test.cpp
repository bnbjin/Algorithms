#include "maxsubarray.h"
#include <iostream>

int main()
{
	int intarray[] = {-1, -3, 4, 5, 6,-2, -6};
	SUBARRAY_INFO SAI = {0};	

	FindMaxSubArray(&SAI, intarray, 0, sizeof(intarray)/sizeof(int)-1);

	for (unsigned int i = 0 ; i < sizeof(intarray)/sizeof(int); i++)
	{
		std::cout << intarray[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "MaxSubArray: ";
	std::cout << SAI.low << " " << SAI.high << " " << SAI.sum << std::endl;

	return 0;
}
