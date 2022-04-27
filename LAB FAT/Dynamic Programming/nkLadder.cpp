#include<iostream>
using namespace std;


int recur(int n,int k)
{
    if(n==0)return 1;

    if(n<0)
    {
        return 0;
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans+=recur(n-i,k);
    }

    return ans;
    
}

// top down
int topdown(int n,int k,int *dp)
{
    if(n==0)return 1;

    if(n<0)return 0;

    // already computed
    if(dp[n]!=0)
    return dp[n];

    int ans=0;
   
   // recursive case
    for(int i=1;i<=k;i++)
    {
        ans+=topdown(n-i,k,dp);
    }
    return dp[n]=ans;
}

int main()
{
    int n;
    int k;
    int dp[1000]={0};
    cin>>n>>k;
    cout<<recur(n,k);
    cout<<endl;
    cout<<topdown(n,k,dp);
    return 0;
}