#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;


struct activity
{
    int start;
    int end;
};

bool compare(struct activity a,struct activity b)
{
    return a.end<b.end;
}

int numberOfActivity(int n,struct activity arr[])
{
    sort(arr,arr+n,compare);    // sorting the activities in ascending based on their finish time 
    
    
    int count=1;
    cout<<arr[0].start<<" "<<arr[0].end;

    for(int i=1;i<n;i++)
    {
        if(arr[i-1].end<=arr[i].start)
          {
              cout<<arr[i].start<<" "<<arr[i].end;
          }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;

    struct activity arr[n];

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i].start=a;
        arr[i].end=b;
    }

    cout<<numberOfActivity(n,arr);
    return 0;
}