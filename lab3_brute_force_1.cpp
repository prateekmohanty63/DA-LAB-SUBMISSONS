#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int leftIndex = -1, rightIndex = -1;

int maximum_Sum_Subarray(vector<int> vec1, int n)
{
    int ans = INT16_MIN;

    for (int sub_array = 1; sub_array <= n; sub_array++)
    {

        for (int start_index = 0; start_index < n; start_index++)
        {
            if (start_index + sub_array > n)
                break;
            int sum = 0;

            for (int i = start_index; i < (start_index + sub_array); i++)
            {
                sum += vec1[i];
                if (sum > ans)
                {
                    ans = sum;
                    leftIndex = start_index;
                    rightIndex = i;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> vec1;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }

    int res = maximum_Sum_Subarray(vec1, n);
    cout << res << " " << leftIndex << " " << rightIndex;
    return 0;
}