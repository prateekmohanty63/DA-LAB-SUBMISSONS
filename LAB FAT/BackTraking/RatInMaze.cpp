#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>>matrix,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}

bool isSafe(vector<vector<int>>vec1,int x,int y,int n)
{
    if(x<n && y<n && vec1[x][y]==1)
    return true;
    
    return false;

}


bool ratinMaze(vector<vector<int>>vec1,int x,int y,int n,vector<vector<int>>solArray)
{
    // base condition

    if(x==n-1 && y==n-1)
    {
        solArray[x][y]=1;
        return  true;
    }

    if(isSafe(vec1,x,y,n)){
        // rat in move here
        solArray[x][y]=1;

        // move forward (right)
        if(ratinMaze(vec1,x+1,y,n,solArray)){
            return true;
        }

        // move downword
        if(ratinMaze(vec1,x,y+1,n,solArray)){
            return true;
        }
        // backtrack
        solArray[x][y]=0;
        return false;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;

    vector<vector<int>>matrix;
    vector<vector<int>>solArray;


 for(int i=0;i<n;i++)
    {
        vector<int>vec1;
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            vec1.push_back(a);
        }
        matrix.push_back(vec1);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        solArray[i][j]=0;
    }

   
     
    if(ratinMaze(matrix,0,0,n,solArray)){
         for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<solArray[i][j]<<" ";

        cout<<endl;
    }

    }
    else{
        cout<<"Path doesn't exists";
    }

    return 0;
}