#include <bits/stdc++.h>
using namespace std;

void solution(int arr[],int k)
{
    priority_queue<int,vector<int>, greater<int> > q;
    int sum = 0;
    for(int i=0;i<k;i++)
        q.push(arr[i]);
    while(q.size()!=1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        sum+=a+b;
        q.push(a+b);
    }
    cout<<sum<<endl;
}

int main()
{
    int arr[] = {4,3,2,6};
    int k = sizeof(arr)/sizeof(*arr);
    solution(arr,k);
}