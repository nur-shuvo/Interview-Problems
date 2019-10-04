#include<stdio.h>
#include<iostream>
//zone
using namespace std;
//0 -> white (non visited vertices)
//1 -> gray (in process verices)
//2 -> black(fully processed veritces)
int graph[1000][1000]; /* if graph[m][n]=1 then an edge from m to n vertex */
int N,e,node1;
int color[10005];
int parent[10005];
bool dfs(int vertex)
{
    color[vertex] = 1;
    for(int i = 0 ; i  < N; i++){

        if(graph[vertex][i]==1){  /* if adjacent */
            if(color[i] == 1){
                node1 = vertex;
                return true ; //BACK EDGE //cycle
            }
            if(color[i] == 0){
                parent[i] = vertex;
                if(dfs(i)){
                    return true;
                }
            }
         }
    }
    color[vertex] = 2; //fully processed node
    return false;
}
int main()
{
    int t; cin>>t;

    while(t--){

        cin>>N>>e;


        for(int i=0;i<N-1;i++){
            color[i] = 0;
            parent[i] = i;
        }

        for(int i = 0; i  < e; i++){
            int x,y;
            cin>>x >> y;
            graph[x][y] = 1;
        }
        int flag = 0;
        for(int i = 0; i < N; i++){
            if(color[i] == 0){
                if(dfs(i)){
                    flag = 1;

                    int now = node1;
                    cout<<now<<" ";
                    while(now!=i){
                        now = parent[now];
                        cout<<now<<" ";
                    }

                    break;
                }
            }
        }
//        if(flag){
//            cout<<"1\n";
//        }
//        else
//            cout<<"0\n";

        /* clear */
        for(int i=0;i<N;i++) color[i] = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                graph[i][j]=0;
        }



    }
}

