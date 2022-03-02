#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void pop_front(vector<int> &v)
{
    if (v.size() > 0)
    {
        v.erase(v.begin());
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec1;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }

    vector<int> vec2;
    vec2 = vec1;

    int m = 0;

    sort(vec2.begin(), vec2.end());
    m = vec2[0];
    int k = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int max = INT16_MAX;
        int b = vec2[i];

        int index = -1;
        for (int j = 0; j < vec1.size(); j++)
        {
            if (vec1[j] > b && vec1[j] <= max)
            {
                max = vec1[j];
                index = j;
            }
        }
        // cout << vec1[index] << " ";

        swap(vec1[index], vec1[k++]);
    }

    swap(m, vec1[0]);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << vec1[i] << " ";
    }

    return 0;
}