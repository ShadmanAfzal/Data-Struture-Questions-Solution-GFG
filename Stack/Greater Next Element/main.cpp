#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> solution(n, -1);
    s.push(arr.at(0));

    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && s.top() < arr.at(i))
        {
            solution[i-1] = arr[i];
            s.pop();
        }
        s.push(arr.at(i));
    }
    for(int i=0;i<n;i++)
    {
        cout<<solution[i]<<" ";
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(4);
    int size = arr.size();
    print(arr, size);
    return 0;
}