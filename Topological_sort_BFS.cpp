#include<bits/stdc++.h>
using namespace std;

void topo(int s,vector<int>adj[],vector<bool>&visited,vector<int>&indegree)
{
    queue<int>q;
    for(int i=0;i<indegree.size();i++)
        if(indegree[i]==0)
            q.push(i) , visited[i]=true;

    while(!q.empty())
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int child:adj[u])
        {
            indegree[child]--;
            if(indegree[child]==0)
                visited[child]=true , q.push(child);
        }
    }
}

int main()
{
    int V,E;
    cout<<"\nEnter no. of nodes & Edges\n";
    cin>>V>>E;
    vector<int> adj[V] , indegree(V,0);
    vector<bool>visited(V,false);
    cout<<"\nEnter edges\n";
    while(E--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    cout<<"\nTopological sorting is\n";
    for(int i=0;i<V;i++)
        if(visited[i]==false)
            topo(i,adj,visited,indegree);
            
    cout<<endl;
    return 0;
}