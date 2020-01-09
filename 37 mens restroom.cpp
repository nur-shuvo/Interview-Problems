#include<iostream>
using namespace std;
int n,num_of_X;
string s(500,'_');
struct Cell{
    int l;
    int r;
};

class Queue{
public:
    int frontt,rear;
    Cell q[500];
    Queue(){
        frontt=rear=-1;
    }
    void push(Cell x){
        if(frontt==-1) frontt=0;
        rear++;
        q[rear] = x;
    }
    void pop(){
        frontt++;
    }
    Cell front(){
        return q[frontt];
    }
    bool isempty(){
        if(frontt==-1 || frontt>rear) return 1;
    }
};

void print()
{
    for(int i=0;i<n;i++) cout<<s[i]<<" ";
    cout<<endl;
}
int ck;

int main()
{
    cin>>n; int nn = n;
    for(int i=0;i<n;i++) s[i]='_';

    Queue q;
    Cell now; now.l = 0; now.r = n-1;
    q.push(now);
    while(nn--){
        ck = num_of_X;
        Cell now = q.front();
        q.pop();
        int l = now.l; int r = now.r;

        int mid = (l+r)/2;
        Cell left;
        left.l = l;
        left.r = mid-1;

        Cell right;
        right.l = mid+1;
        right.r = r;

        if(right.r>=right.l) q.push(right);
        if(left.r>=left.l) q.push(left);

        s[mid] = 'X';
        print();

    }

}
