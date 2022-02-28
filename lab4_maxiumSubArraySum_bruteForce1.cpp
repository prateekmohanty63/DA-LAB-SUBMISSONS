#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> A, int n)
{
    int i, j, k;
    int max_sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            int sum = 0;
            for (k = i; k < j; k++)
                sum = sum + A[k];
            if (sum > max_sum)
                max_sum = sum;
        }
    }
    return max_sum;
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

    cout << "Maxium sub-array sum is: ";
    cout << maxSubarraySum(vec1, n);
    return 0;
}