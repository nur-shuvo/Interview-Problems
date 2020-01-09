#include<iostream>
using namespace std;

struct Cell
{
    int x;
    int y;
};
int frontt=-1,rear=-1,grid[60][60],vis[60][60],dis[60][60],r,c,sx,sy,l;
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
Cell q[500];
void push(Cell u)
{
    if(frontt==-1) frontt = 0;
    rear++;
    q[rear] = u;
}
void pop()
{
    frontt++;
}
bool isEmpty()
{
    if(frontt==-1 || frontt>rear) return true;
    return false;
}
Cell front()
{
    return q[frontt];
}

bool isValid(int xx,int yy, int p,int q)
{
    bool bidirectional = false;

    if(grid[p][q]==1){
         for(int i=0;i<4;i++){
                int tx = p + fx[i];
                int ty = q + fy[i];

                if(tx==xx && ty==yy) bidirectional = true;

            }
    }
    if(grid[p][q]==2){
             for(int i=0;i<4;i++){
                if(i==0 || i==1 ) continue;
                int tx = p + fx[i];
                int ty = q + fy[i];

                if(tx==xx && ty==yy) bidirectional = true;

            }

    }
    if(grid[p][q]==3){
        for(int i=0;i<4;i++){
                if(i==2 || i==3) continue;
                int tx = p + fx[i];
                int ty = q + fy[i];

                if(tx==xx && ty==yy) bidirectional = true;

            }
    }
    if(grid[p][q]==4){
         for(int i=0;i<4;i++){
                if(i==1 || i==2) continue;
                int tx = p + fx[i];
                int ty = q + fy[i];

                if(tx==xx && ty==yy) bidirectional = true;

            }
    }
    if(grid[p][q]==5){
         for(int i=0;i<4;i++){
                if(i==1 || i==3) continue;
                int tx = p + fx[i];
                int ty = q + fy[i];

                if(tx==xx && ty==yy) bidirectional = true;



            }
    }
    if(grid[p][q]==6){
        for(int i=0;i<4;i++){

                if(i==0||i==3) continue;
                int tx = p + fx[i];
                int ty = q + fy[i];

                if(tx==xx && ty==yy) bidirectional = true;



            }
    }
    if(grid[p][q]==7){
         for(int i=0;i<4;i++){

                if(i==0 || i==2)  continue;
                int tx = p + fx[i];
                int ty = q + fy[i];

                if(tx==xx && ty==yy) bidirectional = true;
            }
    }

    if(p>=0 && q>=0 && p<r && q<c && bidirectional && !vis[p][q]) return true;
    return false;

}


void bfs(int sx,int sy)
{
    Cell src;
    src.x = sx;
    src.y = sy;
    dis[sx][sy] = 0;
    vis[sx][sy] = 1;
    push(src);

    while(!isEmpty()){
        Cell u = front();
        int xx = u.x;
        int yy = u.y;

        pop();

        if(grid[xx][yy]==1){
            for(int i=0;i<4;i++){
                int tx = xx + fx[i];
                int ty = yy + fy[i];

                if(isValid(xx,yy,tx,ty)){
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[xx][yy] + 1;
                    Cell v; v.x = tx, v.y = ty;
                    push(v);
                }

            }
        }
        else if(grid[xx][yy]==2){
            for(int i=0;i<4;i++){
                if(i==0 || i==1 ) continue;
                int tx = xx + fx[i];
                int ty = yy + fy[i];

                if(isValid(xx,yy,tx,ty)){
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[xx][yy] + 1;
                    Cell v; v.x = tx, v.y = ty;
                    push(v);
                }

            }
        }
        else if(grid[xx][yy]==3){
            for(int i=0;i<4;i++){
                if(i==2 || i==3) continue;
                int tx = xx + fx[i];
                int ty = yy + fy[i];

                if(isValid(xx,yy,tx,ty)){
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[xx][yy] + 1;
                    Cell v; v.x = tx, v.y = ty;
                    push(v);
                }

            }
        }
        else if(grid[xx][yy]==4){
            for(int i=0;i<4;i++){
                if(i==1 || i==2) continue;
                int tx = xx + fx[i];
                int ty = yy + fy[i];

                if(isValid(xx,yy,tx,ty)){
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[xx][yy] + 1;
                    Cell v; v.x = tx, v.y = ty;
                    push(v);
                }

            }
        }
        else if(grid[xx][yy]==5){
            for(int i=0;i<4;i++){
                if(i==1 || i==3) continue;
                int tx = xx + fx[i];
                int ty = yy + fy[i];

                if(isValid(xx,yy,tx,ty)){
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[xx][yy] + 1;
                    Cell v; v.x = tx, v.y = ty;
                    push(v);
                }

            }
        }
        else if(grid[xx][yy]==6){
            for(int i=0;i<4;i++){

                if(i==0||i==3) continue;
                int tx = xx + fx[i];
                int ty = yy + fy[i];

                if(isValid(xx,yy,tx,ty)){
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[xx][yy] + 1;
                    Cell v; v.x = tx, v.y = ty;
                    push(v);
                }

            }
        }
        else if(grid[xx][yy]==7){
            for(int i=0;i<4;i++){

                if(i==0 || i==2)  continue;
                int tx = xx + fx[i];
                int ty = yy + fy[i];

                if(isValid(xx,yy,tx,ty)){
                    vis[tx][ty] = 1;
                    dis[tx][ty] = dis[xx][yy] + 1;
                    Cell v; v.x = tx, v.y = ty;
                    push(v);
                }

            }
        }
    }
}

void reset()
{
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            dis[i][j] = 1000000;
            vis[i][j] = 0;
        }
    }
    frontt = -1;
    rear = -1;
}

int main()
{
    int t; cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>r>>c>>sx>>sy>>l;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }

        bfs(sx,sy);
        int maxval = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0){
                    if(dis[i][j]<l) maxval++;
                }
            }
        }

        cout<<maxval<<endl;
        reset();
    }
}

