#include <iostream>
using namespace std;

// using recursion (Brute force)

int N = 100;

int value[100], Kweight[100], Knapsackw = 8, n = 3;
int dp[100][1000000] = {0};

int knapSack(int index, int weight)
{
    if (index >= n)
        return 0;

    // do not take the item at the index
    int ans = knapSack(index + 1, weight);

    //  take the item at the given index
    if (Kweight[index] + weight <= Knapsackw)
    {
        ans = max(ans, value[index] + knapSack(index + 1, Kweight[index] + weight));
    }
    return ans;
}

int MemoknapSack(int index, int weight)
{
    if (index >= n)
        return 0;

    int ans = dp[index][weight];
    // do not take the item at the index
    int ans = knapSack(index + 1, weight);

    if (ans != 0)
        return ans;

    //  take the item at the given index
    if (Kweight[index] + weight <= Knapsackw)
    {
        ans = max(ans, value[index] + knapSack(index + 1, Kweight[index] + weight));
    }
    return ans;
}

int main()
{

    int w, n;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> value[i] >> Kweight[i];
    }

    cout << knapSack(0, 0);

    return 0;
}