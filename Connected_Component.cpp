//Using DFS
#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int>adj[],vector<bool>&visited)
{
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        int child = adj[v][i];
        if(visited[child]==false)
            dfs(child,adj,visited);
    }
}

int main()
{
    int n,m;
    cout<<"Please enter no. of nodes & edges\n";
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<bool> visited(n+1,false);
    cout<<"Please enter nodes\n";
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<"From which vertex you want to start\n";
    int v;
    cin>>v;
    int cc=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            dfs(i,adj,visited);
            cc++;
        }
    }
    cout<<"\nNo. of connected components in this graph \n"<<cc<<endl;

    return 0;
}