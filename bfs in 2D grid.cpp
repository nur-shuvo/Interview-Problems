/* Input : {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}
Output : 6

Input :  {'0', '*', '0', 's'},
         {'*', '0', '*', '*'},
         {'0', '*', '*', '*'},
         {'d', '0', '0', '0'}
Output :  -1
*/


#include<iostream>
#include<stdio.h>
using namespace std;
struct Cell{
    int x;
    int y;
};

Cell q[100];
int n, front = - 1, rear = - 1;
int vis[100][100],dis[100][100];
char grid[100][100];

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};


void push(Cell val) {
      if (front == - 1) front = 0;
      rear++;
      q[rear] = val;
}
void pop() {
      front++;
}

bool isEmpty()
{
    if(front==-1 || front>rear) return true;
    return false;
}

Cell Front()
{
    return q[front];
}

bool isValid(int x,int y)
{
    if(x<n && y<n && x>=0 && y>=0) return true;
    return false;
}

int bfs(Cell src,Cell des)
{
    push(src);
    vis[src.x][src.y] = 1;
    dis[src.x][src.y] = 0;


    while(!isEmpty()){
        Cell u = Front();
        pop();

        int p = u.x;
        int q = u.y;

        for(int i=0;i<4;i++){
            int tx = p + fx[i];
            int ty = q + fy[i];

            if(vis[tx][ty]==0 && grid[tx][ty]!='0' && isValid(tx,ty)){
                vis[tx][ty] = 1;
                Cell v;
                v.x = tx;
                v.y = ty;
                push(v);
                dis[tx][ty] = dis[p][q] + 1;
            }

        }
    }
    return dis[des.x][des.y];
}


int main()
{

    cin>>n;

    // initialize
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) { vis[i][j]=0; dis[i][j]=-1; }

    Cell src,des;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='s'){
                src.x = i;
                src.y = j;
            }
            if(grid[i][j]=='d'){
                des.x = i;
                des.y = j;
            }

        }
    }
    cout<<bfs(src,des)<<endl;
}
