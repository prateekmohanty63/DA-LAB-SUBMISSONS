#include <iostream>
using namespace std;

bool canPlace(int board[][20], int n, int target, int a, int b)
{
    // checking if the element exists in the sub grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                return false;
        }
    }

    // checking in the row

    for (int i = b; i < n; i++)
    {
        if (board[a][i] == target)
            return false;
    }

    // checking column

    for (int i = a; i < n; i++)
    {
        if (board[i][b] == target)
            return false;
    }
    return true;
}

int main()
{

    return 0;
}