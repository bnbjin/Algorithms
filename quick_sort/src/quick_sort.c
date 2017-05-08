#include "quick_sort.h"

void quick_sort(
        int *_array,
        const int _begin,
        const int _end)
{
    if (_begin >= _end)
    {
        return;
    }

    int key_index = _begin;
    int flow_index = key_index;
    int temp;


    for (int i = key_index + 1; i <= _end; i++)
    {
        if (_array[i] < _array[key_index])
        {
            temp = _array[i];
            _array[i] = _array[++flow_index];
            _array[flow_index] = temp;
        }
    }

    temp = _array[flow_index];
    _array[flow_index] = _array[key_index];
    _array[key_index] = temp;

    quick_sort(_array, _begin, flow_index - 1);
    quick_sort(_array, flow_index + 1, _end);    
}

