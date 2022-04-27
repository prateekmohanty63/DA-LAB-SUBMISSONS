#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&array,int s,int e)
{
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;

    vector<int>temp;

    while(i<=mid && j<=e)
    {
        if(array[i]<array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else{
            temp.push_back(array[j]);
            j++;
        }
    }

    // copy remianing elements 

    while(i<=mid)
    {
        temp.push_back(array[i++]);
    }
    
    while(j<=e)
    {
        temp.push_back(array[j++]);
    }

    // copy back
    int l=0;
    for(int k=s;k<=e;k++)
    {
       array[k]=temp[l++];
    }
    return ;
}


void mergeSort(vector<int>&array,int s,int e)
{
    // base
    if(s>=e){
        return ;
    }

    // rec case
    int mid=(s+e)/2;
    mergeSort(array,s,mid);
    mergeSort(array,mid+1,e);

    return merge(array,s,e);
}

int main()
{
    
    return 0;
}