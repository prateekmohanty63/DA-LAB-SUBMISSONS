#include<iostream>
using namespace std;

void printMatrix(int mat[][9],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<mat[i][j]<<" ";

        cout<<endl;
    }

}

bool canPlaceNumber(int mat[][9],int i,int j,int no,int n)
{
    // checking in the row

    for(int c=0;c<n;c++)
    {
        if(mat[i][c]==no)
        return false;
    }

    // checking in the column

    for(int r=0;r<n;r++)
    {
        if(mat[r][j]==no)
        return false;
    }

    // checking in subgrid
    // x coordinate of the subgrid = (x/3)^3 
    // y coordinate of the subgrid = (y/3)^3

    int sx=(i/3)*3;
    int sy=(j/3)*3;

    for(int r=sx;r<sx+3;r++)
    {
        for(int c=sy;c<sy+3;c++)
        {
             if(mat[r][c]==no)return false;
        }
    }


    return true;
}


bool solveSudoku(int mat[][9],int i,int j,int n)
{
    // base case

    if(i==n)
    {
        printMatrix(mat,n);
        return true;
    }

    // if j==n   ( we are at the end of the row)

    if(j==n)
    solveSudoku(mat,i+1,0,n);

    // skip the pre filled cell

    if(mat[i][j]!=0)
    {
        return solveSudoku(mat,i,j+1,n);
    }

    // now we are in the cell to be filled
    for(int no=1;no<=9;no++)
    {
        // wheather it is safe to place the number or not
        
        if(canPlaceNumber(mat,i,j,no,n))
        {
              mat[i][j]=no;

              bool solveSubProblem=solveSudoku(mat,i,j+1,n);

              if(solveSubProblem==true)
              return true;

              // otherwise if the number if not safe , we check for by placing the next number

        }
    }

    // backtrack 
    mat[i][j]==0;
    return false;
}

int main()
{
    int n=9;
    int mat[9][9]={{5,3,0,0,7,0,0,0,0},
                   {6,0,0,1,9,5,0,0,0},
                   {0,9,8,0,0,0,0,6,0},
                   {8,0,0,0,6,0,0,0,3},
                   {4,0,0,8,0,3,0,0,1},
                   {7,0,0,0,2,0,0,0,6},
                   {0,6,0,0,0,0,2,8,0},
                   {0,0,0,4,1,9,0,0,5},
                   {0,0,0,0,8,0,0,7,9}};

    solveSudoku(mat,0,0,n);
    return 0;
}