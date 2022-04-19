#include<iostream>
#include<vector>
using namespace std;


// this is using brute force method
// TIME COMPLEXITY IS : O(N^2)
int bruteForce(string a,string b)
{
     int n=a.length();
     int m=b.length();
     int count=0;
     int indexFound=-1;

     for(int i=0;i<n;i++)
     {
         
         for(int j=0;j<m;j++)
         {
             if(a[i]==b[j])
             {

                  if(j>indexFound){
                     count++;
                     indexFound=i;
                     break;
                 }
             }
         }
     }
     return count;
}

// using recursion
// TIME COMPLEXITY : 0(2^N)

int recur(string a,string b,int n,int m)
{
     if(m==0 || n==0)return 0;

     if(a[n-1]==b[m-1]){
         return 1+recur(a,b,n-1,m-1);     // diagonal movement if string matches

     }
     else{
         return max(recur(a,b,n-1,m),recur(a,b,n,m-1));
     }
}


// optimizing using dynamic programming

int dp(string a,string b,int n,int m,vector<vector<int>>&vec)
{
    if(n==0 || m==0)return 0;

    if(a[n-1]==b[m-1]){
        return vec[n][m]=1+dp(a,b,n-1,m-1,vec);
    }

    if(vec[n][m]!=-1)
    return vec[n][m];
    
      return  vec[n][m]=max(dp(a,b,n-1,m,vec),dp(a,b,n,m-1,vec));
    
}

int main()
{
    string a,b;
     cin>>a>>b; 
   int n=a.length();
   int m=b.length();
    vector<vector<int> > vec1(n+1, vector<int>(m + 1, -1));
   
    cout<<bruteForce(a,b)<<endl;
    cout<<recur(a,b,n,m)<<endl;
    cout<<dp(a,b,n,m,vec1);
}