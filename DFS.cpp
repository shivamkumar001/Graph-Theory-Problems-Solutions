#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int> adj[],vector<bool> visited)
{
    visited[v]=true;
    cout<<v<<"->";

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
    vector<bool> visited(n,false);
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
    dfs(v,adj,visited);
    return 0;
}