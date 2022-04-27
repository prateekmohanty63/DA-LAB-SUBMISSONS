#include<iostream>
#include<vector>
using namespace std;

bool isTrue(vector<int>&vec1,int n)
{
    for(int i=0;i<n;i++)
    {
        if(vec1[i]==0)return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    vector<int>bulb;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        bulb.push_back(a);
    }
    int count=0;
    
    while(isTrue(bulb,n)!=true)
    {
        for(int i=0;i<n;i++)
        {
            if(bulb[i]==0)
            {
                count++;
                bulb[i]=1;
                for(int j=i+1;j<n;j++)
                {
                    if(bulb[j]==0)
                    bulb[j]=1;

                    else
                    bulb[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        cout<<bulb[i]<<" ";
        cout<<endl;
    }
    cout<<count;
    return 0;
}