#include<iostream>
#include<vector>
using namespace std;

void pattern(vector<vector<int>>&mat,int i,int j,string p,string psf,bool &ans)
{
    if(ans)
    {
        return ;
    }

    if(i>=mat.size() || j>=mat[i].size() || mat[i][j]<0)
    return ;

    if(p==psf)
    {
        ans=true;
        return ;
    }
    
    mat[i][j]=-mat[i][j];
    // move forward
    if(i!=mat.size()-1)
    {
        pattern(mat,i+1,j,p,psf+to_string(mat[i+1][j]),ans);
    }

    // move backward
    if(i!=0)
    {
         pattern(mat,i-1,j,p,psf+to_string(mat[i-1][j]),ans);
    }

    // move above

    if(j!=0)
    {
         pattern(mat,i,j-1,p,psf+to_string(mat[i][j-1]),ans);
    }

    // move below

    if(j!=mat[i].size()-1)
    {
       pattern(mat,i,j+1,p,psf+to_string(mat[i][j+1]),ans);
    }
     
     // back track
    mat[i][j]=-mat[i][j];
}

int main()
{
     int  n,m;
     cin>>n>>m;
     vector<vector<int>>vec1;

     for(int i=0;i<n;i++)
     {
         vector<int>vec2;
         for(int j=0;j<m;j++)
         {
             int a;
             cin>>a;
             vec2.push_back(a);
             
         }
         vec1.push_back(vec2);
     }

     string pat;
     cin>>pat;

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             bool ans=false;
             pattern(vec1,i,j,pat,to_string(vec1[i][j]),ans);

             if(ans)
             {
                 cout<<"Pattern Found";
                 exit(0);
             }
         }
 
     }
     cout<<"Pattern Found";
    return 0;
}