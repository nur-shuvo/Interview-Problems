/* shortest path from source to all vertex for weighted graph */

#include<bits/stdc++.h>
#define mx 100
#define INF 1000000000
using namespace std;

vector<int>adj[mx];
int cost[mx][mx],dis[mx];

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    dis[source] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(cost[u][v] + dis[u] < dis[v]){
                dis[v] = cost[u][v] + dis[u];
                q.push(v);
            }
        }
    }
}

int main()
{
    int n,e,source;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v,costt;
        cin>>u>>v>>costt;
        adj[u].push_back(v);
        cost[u][v] = costt;
    }
    cin>>source;

    for(int i=0;i<mx;i++){
        dis[i] = INF;
    }

    bfs(source);

    for(int i=0;i<n;i++){
        cout<<dis[i]<<endl;  /* shortest path from source to i node */
    }

}
