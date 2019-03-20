#include "bubble_sort2.hpp"

#include <utility>

using namespace std;


void bubble_sort2(vector<int> &vec)
{
    for (unsigned i = 0; i < vec.size(); i++)
    {
        bool issorted = true;
        for (unsigned j = 0; j < (vec.size() - i); j++)
        {
            if (vec[j] > vec[j+1])
            {
                swap(vec[j], vec[j+1]);
                issorted = false;
            }
        }
        if (issorted == true)
            break;
    }
}
