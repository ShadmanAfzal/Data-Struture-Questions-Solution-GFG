#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> reverse;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        reverse.push(s[i]);
    }
    s.clear();
    while(!reverse.empty())
    {
        char top = reverse.top();
        reverse.pop();
        s.push_back(top);
    }
    cout<<s<<endl;
}