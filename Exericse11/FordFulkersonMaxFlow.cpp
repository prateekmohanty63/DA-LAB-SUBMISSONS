#include<iostream>
#include<limits.h>
#include<queue>
#include<string.h>
using namespace std;


// Number of vertices in given graph
#define V 6

// function returns true , if it is a path from source to sink

bool sourceTosink(int rGraph[V][V],int s,int t,int parent[])
{

    bool visited[V];

    // initialize the visited array to 0
    memset(visited,0,sizeof(visited));

     // Create a queue, enqueue source vertex and mark source
    // vertex as visited

    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;

    // standard BFS Loop

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v=0;v<V;v++)
        {
            if(visited[v]==false && rGraph[u][v]>0){

                if(v==t){
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }

}

int fordFulkerson(int graph[V][V],int s,int t)
{
    int u,v;

    int rgraph[V][V];
    int max_flow=0;

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        rgraph[i][j]=graph[i][j];
    }

    int parent[V];

    while(sourceTosink(rgraph,s,t,parent)){
        
        int path_flow=INT16_MAX;

        for(int i=t;i!=s;i=parent[i]){
            u=parent[i];
            path_flow=min(path_flow,rgraph[u][i]);
        }

        for(int i=t;i!=s;i=parent[i])
        {
            u=parent[i];
            rgraph[u][i]-=path_flow;
            rgraph[u][i]+=path_flow;
        }

        // Add path flow to overall flow
        max_flow+=path_flow;
    }
    return max_flow;
}

int main()
{
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);
    return 0;
}