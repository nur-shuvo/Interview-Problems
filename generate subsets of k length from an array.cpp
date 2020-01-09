#include<bits/stdc++.h>
using namespace std;

int ara[100],k,n,vis[100];

void dfs(int start,int nodes)
{
    if(nodes==k){
        for(int i=0;i<n;i++){
            if(vis[i]) cout<<ara[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(start==n) return;

    vis[start] = 1;
    dfs(start+1,nodes+1);
    vis[start] = 0;
    dfs(start+1,nodes);

}


int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>ara[i];
    dfs(0,0);
}
