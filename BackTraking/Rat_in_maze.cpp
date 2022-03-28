#include <iostream>
using namespace std;

int printMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

bool isSafe(int arr[][10], int x, int y, int n)
{

    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }

    return false;
}

bool ratInMaze(int arr[][10], int x, int y, int n, int **solArray)
{
    if (x == n - 1 && y == n - 1)
    {
        solArray[x][y] = 1;
        printMatrix(solArray, n);
        return true;
    }
    // if rat is safe make postion as 1 to show path
    if (isSafe(arr, x, y, n))
    {
        solArray[x][y] = 1;

        if (ratInMaze(arr, x + 1, y, n, solArray))
        {
            return true;
        }

        if (ratInMaze(arr, x, y + 1, n, solArray))
        {
            return true;
        }

        // if we cannot move left and right , then we backtrack

        // backtracking
        solArray[x][y] = 0;
    }

    return false;
}

int main()
{
    int matrix[10][10];
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            cin >> matrix[i][j];
        }
    }

    int **solArr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    ratInMaze(matrix, 0, 0, n, solArr);
    return 0;
}