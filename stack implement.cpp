#include<stdio.h>
#include<iostream>
using namespace std;
struct Stack{
    int top=-1,sttack[1000];

    void push(int x){
        top++;
        sttack[top] = x;
    }
    int pop(){
        int p = sttack[top];
        top--;
        return p;
    }
    int topp(){
        return sttack[top];
    }
    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }
};

int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.pop();
    cout<<s.topp()<<endl;
}
