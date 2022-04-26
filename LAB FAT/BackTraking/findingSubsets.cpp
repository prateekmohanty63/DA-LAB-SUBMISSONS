#include<iostream>
using namespace std;

// input = abc
// output = "",a,b,c,ab,bc,ca,abc


void funsSubsets(char *input,char *output,int i,int j)
{
    // base case
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;
        return ;
    }
   // include the ith letter
   output[j]=input[i];
   funsSubsets(input,output,i+1,j+1);

   // exclude the ith letter
   funsSubsets(input,output,i+1,j);

}

int main()
{  
    char input[100];
    char output[100];
    cin>>input;
    funsSubsets(input,output,0,0);
    
    return 0;
}