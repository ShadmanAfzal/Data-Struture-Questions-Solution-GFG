#include <bits/stdc++.h>
using namespace std;


stack<int> reverseStack;

void insert(stack<int> *s)
{
    (*s).push(1);
    (*s).push(2);
    (*s).push(3);
    (*s).push(4);
    (*s).push(5);
}

void display(stack<int> s)
{
    stack<int> temp = s;
    while(!temp.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void insertAtBottom(int x)
{
    reverseStack.push(x);
}

void reverse(stack<int> s)
{
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        insertAtBottom(top);
    }
}

int main()
{
    stack<int> s;
    insert(&s);
    display(s);
    reverse(s);
    display(reverseStack);
}