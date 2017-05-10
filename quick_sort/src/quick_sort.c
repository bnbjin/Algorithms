#include "quick_sort.h"
#include <stdlib.h>
#include <time.h>

void simple_quick_sort(
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

    simple_quick_sort(_array, _begin, flow_index - 1);
    simple_quick_sort(_array, flow_index + 1, _end);    
}

void double_quick_sort(
        int *_array, 
        const int _begin,
        const int _end)
{
    if (_begin >= _end)
    {
        return;
    }

    int key_index = _begin;
    int i = _begin;
    int j = _end + 1;
    int temp;

    while (1)
    {
        do 
        {
            i++;
        } while (i <= _end && _array[i] < _array[key_index]);
    
        do
        {
            j--;
        } while (_array[j] > _array[key_index]);

        if (i > j)
        {
            break;
        }

        temp = _array[i];
        _array[i] = _array[j];
        _array[j] = temp;
    }

    temp = _array[key_index];
    _array[key_index] = _array[j];
    _array[j] = temp;
    key_index = j;

    double_quick_sort(_array, _begin, key_index - 1);
    double_quick_sort(_array, key_index + 1, _end);
}

#define cutoff 2

void quick_sort(
        int *_array,
        const int _begin,
        const int _end)
{
    if ((_end - _begin) < cutoff)
    {
        return;
    }

    int temp;
    srand(time(0));
    int rand_index = rand() % (_end - _begin + 1) + _begin;
    int key_index = _begin;
    temp = _array[rand_index];
    _array[rand_index] = _array[key_index];
    _array[key_index] = temp;    
    
    int i = _begin;
    int j = _end + 1;

    while (1)
    {
        do 
        {
            i++;
        } while (i <= _end && _array[i] < _array[key_index]);
    
        do
        {
            j--;
        } while (_array[j] > _array[key_index]);

        if (i > j)
        {
            break;
        }

        temp = _array[i];
        _array[i] = _array[j];
        _array[j] = temp;
    }

    temp = _array[key_index];
    _array[key_index] = _array[j];
    _array[j] = temp;
    key_index = j;

    quick_sort(_array, _begin, key_index - 1);
    quick_sort(_array, key_index + 1, _end);    
}
