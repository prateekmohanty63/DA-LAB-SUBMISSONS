#include<iostream>
#include<string.h>

using namespace std;


int noOfChar=256;


// finding the next character int the automata

int getNextState(char *pattern,int M,int state,int x)
{

    if(state<M && x==pattern[state])
    return state+1;

    int ns,i;

    for(ns=state;ns<0;ns--){
        if(pattern[ns-1]==x){
            for(i=0;i<ns-1;i++){
              if(pattern[i]!=pattern[state-ns+i])
              break;

              if(ns==i-1)
              return ns;
            }
        }
    }
    return 0;
}

// COMPUTING THE TRANSITION TABLE;

void computeTT(char *pattern,int M,int a[][256]){
    int state,x;

    for (state=0;state<=M;state++){
        for(x=0;x<noOfChar;x++){
          a[state][x]=getNextState(pattern,M,state,x);
        }
    }


}

void search(char *pattern,char *text)
{
    int m=strlen(pattern);
    int n=strlen(text);

    int TF[m+1][noOfChar];

    computeTT(pattern,m,TF);

    int i,state=0;

    for(i=0;i<n;i++){
        state=TF[state][text[i]];

        if(state==m)
        cout<<"Match found at index "<<" "<<i-m+1;
    }
}

int main()
{
    char* text;
    char* pattern;
    cin>>text>>pattern;

    search(pattern,text);


    return 0;
}