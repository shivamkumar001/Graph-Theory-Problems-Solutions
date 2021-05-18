#include<bits/stdc++.h>
using namespace std;

void sssp(int v,vector<int>adj[],vector<bool>&visited,int dist[])
{
    queue<int> q;
    visited[v]=true;
    q.push(v);
    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();
        for(auto child:adj[u])
        {
            if(visited[child]==false)
            {
                dist[child]=dist[u]+1;
                visited[child]=true;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,m;
    cout<<"Please enter no. of nodes & edges\n";
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<bool> visited(n+1,false);
    int dist[n+1]={INT_MAX};
    cout<<"Please enter nodes\n";
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<"\nEnter starting state\n";
    int v;
    cin>>v;
    dist[v]=0;
    sssp(v,adj,visited,dist);
    cout<<"\nDistance from "<<v<<" to Each Node is\n";
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}