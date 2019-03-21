#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void selection_sort(vector<int> &vec)
{
    for (unsigned i = 0; i < vec.size(); i++)
    {
        unsigned min = i;
        for (unsigned j = i; j < vec.size(); j++)
        {
            if (vec[min] > vec[j])
            {
                min = j;
            }
        }

        swap(vec[i], vec[min]);
    }
}

int main(int argc, char *argv[])
{
    vector<int> vec={ 3, 6, 2, 8, 1, 9, 0, 2 };

    selection_sort(vec);

    for (auto &ele: vec)
        cout << ele << " ";

    return 0;
}
