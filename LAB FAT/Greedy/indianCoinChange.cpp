#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n=9;
    

    int currency[]= { 1, 2, 5, 10, 20, 50, 100, 500, 1000};

    

    int change;
    cin>>change;
    int count=0;

    int temp=change;
    int i=n-1;

    while(temp!=0)
    {
        if(currency[i]<=temp)
        {
            while(currency[i]<=temp){
            count++;
            temp-=currency[i];
            }
            
        }
        i--;
    }
    cout<<count;
    return 0;
}