#include <iostream>
#include <vector>
using namespace std;

// longest subsequence using recursion

int LCS(string a, string b, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (a[n - 1] == b[m - 1])
    {
        return 1 + LCS(a, b, n - 1, m - 1);
    }
    else
        return max(LCS(a, b, n - 1, m), LCS(a, b, n, m - 1));
}

// using dynamic programming

int LCSDp(string a, string b, int n, int m)
{
    vector<vector<int>> dp;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string a, b;
    vector<vector<int>> vec1;
    cin >> a >> b;
    cout << "Longest common substring is: ";
    cout << LCS(a, b, a.size(), b.size()) << endl;
    cout << LCSDp(a, b, a.size() - 1, b.size() - 1);
    return 0;
}