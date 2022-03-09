#include <iostream>
using namespace std;

void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int board[][20], int n, int x, int y)
{

    // column

    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }

    // left diag

    int i = x;
    int j = y;

    // Left diag

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // right diag

    i = x;
    j = y;

    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j++;
    }

    return true;
}

// using back tracking

bool solveNQueen(int n, int board[][20], int i)
{

    // base case

    if (i == n)
    {
        printBoard(n, board);
        return true;
    }

    // recursive case
    // try to place a queen in every row

    for (int j = 0; j < n; j++)
    {
        // weather the current i,j is safe or not

        // to check if a queen is safe in the board at location i,j
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);

            if (success)
            {
                return true;
            }

            // Here we backtrack if the place is not safe and increment j and place queen in the next column
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int board[20][20] = {0};
    int n;
    cout << "Enter the dimension of the chess board";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        solveNQueen(n, board, i);
    }

    return 0;
}