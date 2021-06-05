#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top = -1;
    int stack[1000];
    void push(int data)
    {
        top = top + 1;
        stack[top] = data;
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
            return;
        }
        int pop = stack[top];
        top = top - 1;
        cout<<"Element pop out is << "<<pop<<endl;
    }

    void printStack()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
            return;
        }
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Stack stack = Stack();
    stack.printStack();
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.printStack();
    stack.pop();
    stack.printStack();
}