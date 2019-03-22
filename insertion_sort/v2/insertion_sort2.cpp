#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void insertion_sort2(vector<int> &vec)
{
    for (unsigned i = 1; i < vec.size(); ++i)
    {
        int value = vec[i];

        int j = i;
        while (j > 0)
        {
            vec[j] = vec[j-1];

            if (value < vec[j-1])
                break;

            j--;
        }

        vec[j] = value;
    }
}

int main()
{
    vector<int> vec={ 3, 6, 8, 0, 2, 1 };

    insertion_sort2(vec);

    for (auto &ele : vec)
        cout << ele << " ";

    return 0;
}
