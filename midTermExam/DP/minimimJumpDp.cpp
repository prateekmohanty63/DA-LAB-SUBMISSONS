#include<iostream>
#include<vector>
using namespace std;

// Top down (memoization)

int min_jump(vector<int>arr,int n,vector<int>dp,int i)
{
      // base case

      if(i==n-1)
      {
          return 0;
      }

      if(i>=n)return INT16_MAX;

      if(dp[i]!=0)
      return dp[i];

      // assume 
      int steps=INT16_MAX;

      int max_jump=arr[i];

      for(int jump=1;jump<=max_jump;jump++)
      {
          int next_cell=i+jump;

          int subProblem=min_jump(arr,n,dp,next_cell);

          if(subProblem!=INT16_MAX)
          {
              steps=min(steps,subProblem+1);
          }
      }

      return dp[i]=steps;
}

int main()
{
    vector<int>arr{3,4,2,1,2,3,7,1,1,3};

    int n=arr.size();
    vector<int>dp(n,0);

    cout<<min_jump(arr,n,dp,0)<<endl;
    return 0;
}