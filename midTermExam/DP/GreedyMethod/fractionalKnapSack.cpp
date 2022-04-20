#include<iostream>
#include<algorithm>
using namespace std;

struct Item
{
    double weight;
    double profit;
};

    // Item()
    // {

    // }

    // Item(int weight,int profit)
    // {
    //     this->weight=weight;
    //     this->profit=profit;
    // }

    // function to compare two weight values 

    bool compare(Item a,Item b)
    {
        double r1=(double)a.profit/(double)a.weight;
        double r2=(double)b.profit/(double)a.weight;

        return r1>r2;
    }

    double fractionalKnapSack(int n,int w,struct Item arr[])
    {
        double cost=0;

        int temp=w;

        sort(arr,arr+n,compare);    // sorting the array of items based on the highest profit/weight

        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=temp)
            {
                cost+=arr[i].profit;
                temp-=arr[i].weight;
            }

            else if(arr[i].weight>temp)
            {
               double a=((double)temp/(double)arr[i].weight);
               cout<<a;
                cost+=arr[i].profit*(double)(temp/(double)arr[i].weight);
                break;

            }
        }
        return cost;
    }


int main()
{
    int w;
    cout<<"Enter the weight of the knapsack: "<<endl;
    cin>>w;

    int n;
    cout<<"Enter the number of items present: "<<endl;
    cin>>n;

    Item arr[n];

    for(int i=0;i<n;i++)
    {
        int weight,profit;
        cout<<"Enter the weight of the item and the profit: ";
        cin>>weight>>profit;
        arr[i].weight=weight;
        arr[i].profit=profit;
        
    }

    cout<<"The maximum profit that can be generated is: ";
    cout<<fractionalKnapSack(n,w,arr);


    
    
    return 0;
}