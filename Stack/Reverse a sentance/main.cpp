#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string temp = "";
    stack<char> reversal;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            while (!reversal.empty())
            {
                temp += reversal.top();
                reversal.pop();
            }
            if (i != s.length() - 1)
            {
                temp += '.';
            }
            continue;
        }
        reversal.push(s[i]);
    }
    return temp;
}

int main()
{
    string s = "pqr.mno";
    s.push_back('.');
    cout << reverseWords(s);
}