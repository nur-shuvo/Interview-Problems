#include <iostream>
using namespace std;
int q[100], n = 100, front = - 1, rear = - 1;

void push(int val) {
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

int Front()
{
    return q[front];
}


int main()
{
     push(5);
     push(3);
     cout<<Front()<<endl;
     pop();
     cout<<isEmpty()<<endl;
     pop();
     cout<<isEmpty()<<endl;
}
