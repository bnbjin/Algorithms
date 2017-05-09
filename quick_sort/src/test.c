#include "quick_sort.h"
#include <stdio.h>

int main()
{
    int array[] = { 9, 7, 5, 3, 2, 1 };
    
    // print original array
    printf("original array: \n");
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // quick_sort
    //quick_sort(array, 0, sizeof(array)/sizeof(int) -1);
    
    // double_quick_sort
    double_quick_sort(array, 0, sizeof(array)/sizeof(int) -1);

    // print result array
    printf("result array: \n");
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
