// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.

//vis[i] = -1 /* no color */
//vis[i] = 0 /* color-1 */
//vis[i] = 1 /* color-2 */

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--){
		memset(g,0,sizeof (g));
		int n;
		cin>>n;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>g[i][j];
			}
		}
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}

bool dfs(int u, int G[][MAX], int  V, int vis[],int color[])
{
     bool flag = true;
     vis[u] = 1;
     if(color[u]==-1) color[u] = 0;

     for(int i=0;i<V;i++){
        if(G[u][i]){
            int v = i;
            if(vis[v]==0){
                vis[v] = 1;
                color[v] = 1 - color[u];
                flag = flag & dfs(v,G,V,vis,color);
            }
            else{
                if(color[u]==color[v]){
                    return false;
                }
            }
        }
     }
     return flag;
}

bool isBipartite(int G[][MAX],int V)
{
    int vis[V],color[V];

    for(int i=0;i<V;i++) { vis[i] = 0; color[i] = -1; }

    for(int i=0;i<V;i++){
        if(!dfs(i,G,V,vis,color)) return false;
    }

    return true;
}
