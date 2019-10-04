#include <stdio.h>
#include<iostream>
using namespace std;
const int inf = 10000000;
const int bound = 500;

void path_print(int next[bound][bound],int source,int des)
{
    int now = source;

    while(now!=des){
        cout<<now<<" ";
        now = next[now][des];
    }
    cout<<des<<endl;
}


int main()
{
    int t; cin>>t;
    while(t--){
    int V; cin>>V;
    int cost[V+1][V+1],next[bound][bound];

    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
        cin>>cost[i][j];
        }
    }

//    inititialize next[i][j] array. it contains porer node to go j from i node
    for(int i=1;i<=V;i++){ for(int j=1;j<=V;j++){
        next[i][j] = j; /* as nothing in middle initially */
        }
    }

    /* Floyd Warshal */
    for(int k=1;k<=V;k++){  /* majher node */
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(cost[i][j]>cost[i][k] + cost[k][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
           if(cost[i][j]==inf) cout<<"INF"<<" ";
           else cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
//    path_print(next,1,3);
  }
}
