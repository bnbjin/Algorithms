#include "insertion_sort.h"

void insertion_sort(
        int *_array,
        int _begin,
        int _end)
{
    int key;
    int temp;
    int i;
    int j;
    for (i = _begin + 1; i <= _end; i++)
    {
        key = _array[i];
        for (j = i; j > _begin && _array[j - 1] > key; j--)
        {
           _array[j] = _array[j -1]; 
        }
        _array[j] = key;
    }
}
