#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findPattern(vector<vector<int>>&mat,int i,int j,string p,string psf,bool &ans)
{
    // if we find answer return  (base condition)
    
    if(ans)return ;

    // if going out of bound return 

    if(i>=mat.size() || j>=mat[i].size() || mat[i][j]<0)
    return ;

    // if found match, make ans as true
    if(p==psf)
    {
        ans=true;
        return ;
    }

    // now we have 4 choices of direction to move from (forward,backward,left,right)

    // moving forward if i not out of bound

    mat[i][j]=-mat[i][j];  // mark that we are moving through the string

    if(i!=mat.size()-1)
    {

        findPattern(mat,i+1,j,p,psf+to_string(mat[i+1][j]),ans);
    }

    // moving backward in same row

    if(i!=0)
    {
        findPattern(mat,i-1,j,p,psf+to_string(mat[i-1][j]),ans);
    }

    // move upward

    if(j!=0)
    {
        findPattern(mat,i,j-1,p,psf+to_string(mat[i][j-1]),ans);
    }

    if(j!=mat[i].size()-1)
    {
        findPattern(mat,i,j+1,p,psf+to_string(mat[i][j+1]),ans);
    }

    // if none of these condition work , then we backtrack
    mat[i][i]=-mat[i][j];
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }

    string pattern;
    cin>>pattern;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool ans=false;
            findPattern(matrix,i,j,pattern,to_string(matrix[i][j]),ans);
            if(ans){
            cout<<"String found"<<endl;
            exit(0);
            }
          //  break;
        }

       
    }
     cout<<"Pattern not found";
    return 0;
}