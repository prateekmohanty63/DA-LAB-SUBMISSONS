#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isSafe(vector<vector<int>>matrix1,int i,int j,int n)
{
    if(i<n && j<n && matrix1[i][j]==1)
    {
        return true;
    }

    return false;
}

bool ratInMaze(vector<vector<int>>maze,int x,int y,int n,vector<vector<int>>solArr)
{
      // base case
      if(x==n-1 && y==n-1 && maze[x][y]==1)
      {
          solArr[x][y]=1;
          return true;

      }

      // rat moving front
      if(isSafe(maze,x,y,n))
      {
         if(solArr[x][y]==1)
         return false;

         solArr[x][y]=1;

         if(ratInMaze(maze,x+1,y,n,solArr))
         {
             return true;
         }

         if(ratInMaze(maze,x,y+1,n,solArr))
         {
             return true;
         }

         // if no movement can be made then backtrack and make previous step as 0
         solArr[x][y]=0;
         return false;
      }
      return false;
}

int main()
{
    vector<vector<int>>maze;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        vector<int>vec1;
        for(int j=0;j<n;j++)
        {
              int a;
              cin>>a;
              vec1.push_back(a);
        }
        maze.push_back(vec1);
    }
    vector<vector<int>>solArray;

    for(int i=0;i<n;i++)
    {
        vector<int>vec1;
        for(int j=0;j<n;j++)
        {
           vec1.push_back(1);
        }
        solArray.push_back(vec1);
    }
    if(ratInMaze(maze,0,0,n,solArray))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<solArray[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    cout<<"Cannot reach";
    return 0;
}