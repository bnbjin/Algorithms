#include "insertion_sort.h"
#include <stdio.h>

int main()
{
    int array[] = { 9, 6, 3, 1};
    
    printf("Original array:\n");
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    insertion_sort(array, 0, sizeof(array)/sizeof(array[0]) - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");


    return 0;
}
