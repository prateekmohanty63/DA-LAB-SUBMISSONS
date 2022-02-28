#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec1;

    cout << "Enter the elements of the vector" << endl;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }
    // int sum = 0;
    int max = INT16_MIN;
    int leftIndex = -1, rightIndex = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int sum = vec1[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += vec1[j];

            if (sum > max)
            {
                max = sum;
                leftIndex = i;
                rightIndex = j;
            }
        }
    }

    cout << max << " " << leftIndex << " " << rightIndex;

    return 0;
}