#include <iostream>
#include <vector>
using namespace std;

// subsequence may not be continous

// using recursion
string longestCommonSubsequence;

int lcs(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (x[m - 1] == y[n - 1])
    {
        longestCommonSubsequence += x[m - 1];
        return 1 + lcs(x, y, m - 1, n - 1);
    }

    else
        return max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
}

// using dynamic programming

int lcsDp(string a, string b, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return 0;

    if (a[m - 1] == b[n - 1])
    {
        return dp[m][n] = 1 + lcsDp(a, b, m - 1, n - 1, dp);
    }

    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = max(lcsDp(a, b, m - 1, n, dp), lcsDp(a, b, m, n - 1, dp));
}

int main()
{
    string string1, string2;
    cin >> string1 >> string2;
    int n = string1.size();
    int m = string2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << "Hence the longest common subsequence is: ";
    int a = lcs(string1, string2, n, m);
    int b = lcsDp(string1, string2, n, m, dp);
    cout << a << endl;
    cout << b << endl;
    // cout << longestCommonSubsequence;
    return 0;
}