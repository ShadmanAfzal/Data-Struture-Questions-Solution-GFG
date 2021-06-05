#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> generator;
    int n;
    cin>>n;
    generator.push("1");
    while(n--)
    {
        string s1,s2;
        s1 = generator.front();
        generator.pop();
        cout<<s1<<" ";
        s2 = s1;
        generator.push(s1.append("0"));
        generator.push(s2.append("1"));
    }

}