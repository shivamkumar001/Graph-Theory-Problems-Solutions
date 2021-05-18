// WBy using BFS Approach

#include<bits/stdc++.h>
using namespace std;

void bfs(int v,vector<int> adj[],vector<bool> &visited)
{
    queue<int> q;
    visited[v]=true;
    q.push(v);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto child:adj[u])
        {
            if(visited[child]==false)
                {
                    visited[child]=true;
                    q.push(child);
                }
        }
    }
}
int main()
{
    cout<<"Enter no. of vertex and edges\n";
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<bool> visited(n+1,false);
    cout<<"\nEnter edges\n";
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cc=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            bfs(i,adj,visited);
            cc++;
        }
    }
    cout<<"\nNo. of Islands in this graph using BFS\n"<<cc<<endl;
}