/* Checks for if an undirected graph has a cycle, not to print all cycles obviously */

#include<bits/stdc++.h>
using namespace std;

bool bfs(int s,vector<int>adj[],int vis[],int parent[])
{
    queue<int>q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(vis[v]==0){
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
            else{
                if(parent[u]!=v){
                    /* cycle found */
                    return true;
                }
            }
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   int vis[V],parent[V];

   for(int i=0;i<V;i++) vis[i] = 0;

   for(int i=0;i<V;i++){
       if(!vis[i]){
           if(bfs(i,adj,vis,parent)){
               return true;
           }
       }
   }
   return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int V, E;
        cin>>V>>E;
        // array of vectors to represent graph
        vector<int> adj[V+1];

        int u, v;
        for(int i=0;i<E;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}
