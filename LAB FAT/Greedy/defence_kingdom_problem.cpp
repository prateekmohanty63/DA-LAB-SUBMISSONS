#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct position
{
    int x;
    int y;
};

bool cmp(struct position a,struct position b)
{
    return a.x<b.x;
}

bool cmp1(struct position a,struct position b)
{
    return a.y<b.y;
}

// SORT BOTH X AND Y POSITION
// SUBTRACT CONSECUTIVE ELEMETS
// THEN SORT  BOTH X AND Y
// TAKE MAX OF BOTH

int main()
{
    int n,m;
    cin>>n>>m;

    cout<<"Enter the cooordinates of the watch towers: ";
   struct  position arr[3];

    for(int i=0;i<3;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[i].x=x;
        arr[i].y=y;

    }

   

    sort(arr,arr+3,cmp);

    //  for(int i=0;i<3;i++)
    // {
    //     cout<<arr[i].x<<" "<<arr[i].y<<endl;
    // }
   
   // vector to store change in x and change in y
   vector<int>changex,changey;


   changex.push_back(arr[0].x-1);

   for(int i=0;i<2;i++)
   {
       int b=arr[i+1].x-arr[i].x-1;
       changex.push_back(b);
   }

   changex.push_back(n-arr[2].x);

   // SORTING BASED ON Y COORDINATES

   sort(arr,arr+3,cmp1);
   

   changey.push_back(arr[0].y-1);

   for(int i=0;i<2;i++)
   {
       int a=arr[i+1].y-arr[i].y-1;
       changey.push_back(a);
   }

   changey.push_back(m-arr[2].y);

   // sorting both the arrays
   sort(changex.begin(),changex.end());
   sort(changey.begin(),changey.end());

   for(int i=0;i<4;i++)
   {
       cout<<changex[i]<<" ";

   }
   cout<<endl;
   for(int i=0;i<4;i++)
   {
       cout<<changey[i]<<" ";

   }

   cout<<"The maximum undefended area is: "<<changex[3]*changey[3];
 

    return 0;
}