#include "heap_sort.h"
#include <iostream>

int main()
{
    int array[] = { 2, 8, 7, 3, 5, 4, 6, 9, 1, 0 };

    std::cout << "the original\n"; 
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    heap_sort(array, sizeof(array)/sizeof(array[0]));

    std::cout << "the sorted\n"; 
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
