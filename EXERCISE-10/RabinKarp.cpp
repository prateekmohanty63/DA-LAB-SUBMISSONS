#include <iostream>
#include <math.h>
using namespace std;

int hashValue(string a, int m)
{
    int val = 0;

    for (int i = 0; i < m; i++)
    {
        int x = (int)a[i] - 96;
        val += x * pow(10,m - 1 - i);
    }
    return val;
}

int main()
{

    string text,pattern;
    cin>>text>>pattern;

    int m=pattern.size();
    int n=text.size();

    int HashvaluePattern=hashValue(pattern,m);
    int flag=0;

    

    

    for(int i=0;i<n;i++){
       
       string a="";
       for(int j=i;j<m+i && j<n;j++){
           a+=text[j];
       }

       int hashValueText=hashValue(a,m);
      
       if(hashValueText==HashvaluePattern){
          

           int l=0;
          // cout<<i;
           for(int k=i;k<m+i;k++){
               if(text[k]==pattern[l]){
                   l++;
               }
           }
           if(l==m){
               cout<<"Pattern found at index"<<" "<<i;
               flag=1;
               break;
           }
       }
    }

    if(flag==0)
    cout<<"Pattern not found";
    return 0;
}