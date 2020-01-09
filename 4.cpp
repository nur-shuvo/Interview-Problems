#include<bits/stdc++.h>
using namespace std;

int mat[101][101], n, e, vis[101];
bool flag = true;
int par[101],last;

bool dfs(int u,int cpy)
{
    vis[u] = 1;
    for(int i=0;i<n;i++){
        if(mat[u][i]){
            if(i==cpy) { last = u; return false; }
            if(!vis[i]){
                flag = flag & dfs(i,cpy);
                par[i] = u;
            }
        }
    }
    return flag;

}

int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v; cin>>u>>v;
        mat[u][v] = 1;
    }

    for(int i=0;i<n;i++){
        if(!dfs(i,i)){
            /* found cycle */
            cout<<"cycle"<<endl;

            int now = last;
            vector<int>v;
            while(1){
                v.push_back(now);
//                cout<<now<<endl;
                if(now==i) break;
                now = par[now];
            }

            reverse(v.begin(),v.end());
            for(auto x: v) cout<<x<<" ";
            cout<<i<<endl;

        }
        flag = true;
        for(int i=0;i<n;i++) vis[i] = 0;
    }


}
