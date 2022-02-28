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

    int maxim = INT16_MIN;
    int leftIndex = -1, rightIndex = -1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += vec1[i];
        maxim = max(sum, maxim);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxim;
}