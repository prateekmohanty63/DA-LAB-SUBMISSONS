#include <iostream>
#include <vector>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int maxSubArraySum(vector<int> vec1, int low, int high)
{
    if (high <= low)
        return vec1[low];

    int mid = (low + high) / 2;

    int left_max = INT16_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += vec1[i];

        if (sum > left_max)
            left_max = sum;
    }

    int right_max = INT16_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += vec1[i];
        if (sum > right_max)
            right_max = sum;
    }

    int max_left_right = max(maxSubArraySum(vec1, low, mid), maxSubArraySum(vec1, mid + 1, high));

    return max(max_left_right, left_max + right_max);
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

    cout << "Maximum sub array sum is: ";
    int b = maxSubArraySum(vec1, 0, n - 1);
    cout << b;

    return 0;
}