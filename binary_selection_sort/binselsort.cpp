#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void binary_selection_sort(vector<int> &vec)
{
    for (unsigned i = 1; i < vec.size(); i++)
    {
        unsigned lower = 0;
        unsigned upper = i - 1;

        while (lower < upper)
        {
            unsigned middle = (lower + upper) / 2;

            if (vec[i] > vec[middle])
            {
                lower = middle + 1;
            }
            else //(vec[middle] >= vec[i])
            {
                upper = middle;
            }
        }

        unsigned location;
        if (vec[i] < vec[lower])
            location = lower;
        else
            location = lower+1;

        int value = vec[i];
        for (unsigned j = 0; j < (i - location); ++j)
        {
            vec[i-j] = vec[i-j-1];
        }
        vec[location] = value;
    }
}

int main(int argc, char *argv[])
{
    vector<int> vec={ 5, 3, 1, 2, 6, 0, -1, -2 };

    binary_selection_sort(vec);

    for (unsigned i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
