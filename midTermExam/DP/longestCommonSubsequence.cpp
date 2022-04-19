#include<iostream>

using namespace std;

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

int main()
{
    string a,b;

    cin>>a>>b; 

    cout<<bruteForce(a,b);
}