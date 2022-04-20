#include<iostream>
using namespace std;

void printMatrix(int board[][20],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<board[i][j]<<" ";

        cout<<endl;
    }
    
}

bool canPlace(int board[][20],int n,int r,int c)
{
     // column
     for(int i=0;i<r;i++)
     {
         if(board[i][c]==1)return false;
     }

     // left diagonal
     int j=c;
     for(int i=r;i>=0 && j>=0;i--,j--)
     {
         if(board[i][j]==1)return false;
     }

     // right diagonal
     j=c;
     for(int i=r;i>=0 && j<n;i--,j++)
     {
         if(board[i][j]==1)return false; 
     }
     return true;
}

bool solveNQueen(int n,int board[][20],int i)
{
    if(i==n)
    {
        printMatrix(board,n);
        return true ;
    }
    
    // recursive case
    // try to place the queen at every row

    for(int j=0;j<n;j++)
    {
          if(canPlace(board,n,i,j)){
              board[i][j]=1;
              bool success=solveNQueen(n,board,i+1);

              if(success)return true;

               // if unsafe state then backtrack
                board[i][j]=0;
          }

         
    }
    return false;
     
}

int main()
{
    int board[20][20]={0};

    int n;
    cin>>n;
    solveNQueen(n,board,0);
    return 0;
}