#include<iostream>
#include<stdio.h>
#define mx 100
using namespace std;

struct Edge{
    int a;
    int b;
    int cost;
};

void s_wap(int i,int j,Edge arr[])
{
    int p = arr[i].a;
    int q = arr[i].b;
    int c1 = arr[i].cost;

    arr[i].a = arr[j].a;
    arr[i].b = arr[j].b;
    arr[i].cost = arr[j].cost;

    arr[j].a = p;;
    arr[j].b = q;
    arr[j].cost = c1;
}

int main()
{
     int t; cin>>t;
     while(t--){
     int n,e;
     cin>>n>>e;
     Edge arr[1001];
     for(int i=0;i<e;i++){
        int u,v,c;
        cin>>u>>v>>c;
        arr[i].a = u;
        arr[i].b = v;
        arr[i].cost = c;
     }

     /* sort edges according to cost */

     for(int i=0;i<e;i++){
        for(int j=0;j<e;j++){
            if(arr[j].cost > arr[i].cost){
                s_wap(i,j,arr);
            }
        }
     }
     int vis[n+1]; for(int i=1;i<=n;i++) vis[i]=0;
     int total = 0; int cnt = 0;
     for(int i=0;i<e;i++){
        int p = arr[i].a;
        int q = arr[i].b;

        if(vis[p]==1 && vis[q]==1) continue; /* cycle */

        vis[p] = vis[q] = 1;
        total+= arr[i].cost;
        cnt++;
        if(cnt==n-1) break;
     }
     cout<<total<<endl;
     }
}
