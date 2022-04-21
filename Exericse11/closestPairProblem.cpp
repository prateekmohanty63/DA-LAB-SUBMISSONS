#include<iostream>
#include<cmath>
using namespace std;

class Points
{
    public:
    int x;
    int y;
};

float distance(int x1,int y1,int x2,int y2)
{
    int xdis=x1-x2;
    int ydis=y1-y2;

    float res=pow(xdis*xdis + ydis*ydis,0.5);

    return res;
}

void closestPairPoints(struct Points point1[],int n)
{
    int min=INT16_MAX;
    int xindex1=-1,yindex1=-1;
    int xindex2=-1,yindex2=-1;
    for(int i=0;i<n;i++)
    {
        int xpoint=point1[i].x;
        int ypoint=point1[i].y;

        for(int j=i+1;j<n;j++)
        {
            int xpoint1=point1[j].x;
            int ypoint1=point1[j].y;

            float t=distance(xpoint,ypoint,xpoint1,ypoint1);

            if(t<min)
            {
                min=t;
                xindex1=point1[i].x;
                yindex1=point1[i].y;

                xindex2=point1[j].x;
                yindex2=point1[j].y;
            }
        }
    }

    cout<<"Closest pair of points are: "<<"("<<xindex1<<","<<yindex1<<")";
    cout<<" "<<"("<<xindex2<<","<<yindex2<<")"<<endl;
    cout<<"The distance between the points are: "<<distance(xindex1,yindex1,xindex2,yindex2);
}

int main()
{
    cout<<"Enter the number of points: ";
    int n;
    cin>>n;

    struct Points arr[n];

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[i].x=x;
        arr[i].y=y;
    }

      closestPairPoints(arr,n);
   

    return 0;
}