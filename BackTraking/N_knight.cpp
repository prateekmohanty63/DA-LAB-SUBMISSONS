#include <iostream>
#include <vector>
using namespace std;

int printMatrix(vector<vector<int>> vec1, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec1[i][j];
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> vec1, int x, int y, int n)
{

    if (y - 2 >= 0 && vec1[x][y - 2] == 1)
        return false;

    if (x + 2 < n && y - 1 >= 0 && vec1[x + 2][y - 1] == 1)
        return false;

    if (x + 2 < n && y + 1 < n && vec1[x + 2][y + 1] == 1)
        return false;

    return true;
}

bool NKnight(vector<vector<int>> vec1, int n, int i)
{

    if (i == n)
    {
        printMatrix(vec1, n);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(vec1, i, j, n))
        {
            vec1[i][j] = 1;

            bool success = NKnight(vec1, n, i + 1);

            if (success)
                return true;

            // backtrack
            vec1[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n, 0));
    bool flag = 0;

    for (int i = 0; i < n; i++)
        NKnight(vec, n, i);
    return 0;
}