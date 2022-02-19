#include <iostream>
#include <vector>
using namespace std;

/// Divide and conquer

void minMax(vector<int> vec1, int low, int high, int &max, int &min)
{
    // 1 number in the array
    if (low == high)
    {

        if (max < vec1[low])
            max = vec1[low];

        if (min > vec1[high])
            min = vec1[high];

        return;
    }

    // 2 number in an array
    if (high - low == 1)
    {

        if (vec1[low] < vec1[high])
        {
            if (min > vec1[low])
                min = vec1[low];

            if (max < vec1[high])
                max = vec1[high];
        }
        else
        {
            if (min > vec1[high])
                min = vec1[min];

            if (max < vec1[low])
                max = vec1[low];
        }
        return;
    }

    int mid = high + low / 2;

    minMax(vec1, low, mid, max, min);

    minMax(vec1, mid + 1, high, max, min);
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
    int min, max;
    minMax(vec1, 0, vec1.size() - 1, max, min);
    cout << min << " " << max;

    return 0;
}