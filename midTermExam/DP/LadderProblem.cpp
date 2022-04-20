#include<iostream>
#include<vector>

using namespace std;



// recursion  

int ladderProblem(int n,int k)
{
    if(n==0)return 1;
    
    if(n<0)return 0;

    int count=0;
    
    // recursive case
    for(int i=1;i<=k;i++)
    {
         count+=ladderProblem(n-i,k);
    }
    return count;

}


// top down approach 

// top down approach (memoization)

int ladderProblem2(int n,int k,int *dp)
{
    if(n==0) return 1;

    if(n<0)return 0;

    // memoized step
    if(dp[n]!=0)
    return dp[n];
     
     int ans=0;
     for(int i=1;i<=n;i++)
     {
          ans+=ladderProblem2(n-i,k,dp);
     }

     return dp[n]=ans;

}



int ladderProblem1(int n,int k)
{
     int answer[n]={0};

     answer[0]=1;
     answer[1]=1;
     int l=1;

    for(int i=2;i<=k;i++)
    {
         int sum=0;
         for(int j=0;j<i;j++)
         {
             sum+=answer[j];
         }
         answer[i]=sum;
    }

     // after k steps

     for(int i=k+1;i<=n;i++)
     {
         int sum=0;
         for(int j=1;j<=k;j++)
         {
             sum+=answer[i-j];
         }
         answer[i]=sum;
     }

     return answer[n];
}




int main()
{
    int n=4,k=3;
    // cout<<ladderProblem(n,k);
    // cout<<endl;

    // cout<<ladderProblem1(n,k);

    int dp1[1000]={0};
    cout<<ladderProblem2(n,k,dp1);
}