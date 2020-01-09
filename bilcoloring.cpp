// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.

// color[i] = -1 /* no color , non visited */
// color[i] = 0 /* color-1 */
// color[i] = 1 /* color-2 */

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
}

bool dfs(int u, int G[][MAX], int  V, int color[])
{
     bool flag = true;
     if(color[u]==-1) color[u] = 0;

     for(int i=0;i<V;i++){
        if(G[u][i]){
            int v = i;
            if(color[v]==-1){
                color[v] = 1 - color[u];
                flag = flag & dfs(v,G,V,color);
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
    int color[V];

    for(int i=0;i<V;i++) { color[i] = -1; }

    for(int i=0;i<V;i++){
        if(!dfs(i,G,V,color)) return false;
    }

    return true;
}
