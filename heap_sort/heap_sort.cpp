#include "heap_sort.h"
#include "queue/priqueue.h"

void heap_sort(int *_array, const unsigned int _len)
{
    priqueue<int> temp_heap(_len);

    for (int i = 0; i < _len; ++i)
    {
        temp_heap.insert(_array[i]);
    }

    for (int i = 0; i < _len; ++i)
    {
        _array[i] = temp_heap.extractmin();
    }
}
