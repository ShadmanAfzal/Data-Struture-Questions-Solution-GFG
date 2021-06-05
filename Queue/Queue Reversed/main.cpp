#include <bits/stdc++.h>
using namespace std;

void printReversed(queue<int> q)
{
    stack<int> reverse;
    while(!q.empty())
    {
        int item = q.front();
        q.pop();
        reverse.push(item);
    }
    cout<<reverse.size()<<endl;
    while(!reverse.empty())
    {
        cout<<reverse.top()<<" ";
        reverse.pop(); 
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    printReversed(q);
}