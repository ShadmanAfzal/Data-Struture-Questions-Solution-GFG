#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}

queue<int> modifyQueue(queue<int> q, int k)
{
    deque<int> dq;
    queue<int> sol;
    while (!q.empty())
    {

        if (k > 0)
        {
            dq.push_front(q.front());
            q.pop();
            k--;
        }
        else
        {
            dq.push_back(q.front());
            q.pop();
        }
    }
    while (!dq.empty())
    {
        sol.push(dq.front());
        dq.pop_front();
    }
    return sol;
}