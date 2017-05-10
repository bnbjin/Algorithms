#include "quick_sort.h"
#include <stdio.h>

int main()
{
    int array[] = { 13, 12, 11, 10, 4,  9, 8, 7, 6, 5, 3, 2, 1 };
    
    // print original array
    printf("original array: \n");
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // simple_quick_sort
    //simple_quick_sort(array, 0, sizeof(array)/sizeof(int) - 1);
    
    // double_quick_sort
    //double_quick_sort(array, 0, sizeof(array)/sizeof(int) - 1);

    // quick_sort
    quick_sort(array, 0, sizeof(array)/sizeof(array[0]) - 1);
    // insertion_sort

    // print result array
    printf("result array: \n");
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
