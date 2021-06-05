#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pattern = "[({[([{}])]})}";
    stack<char> validator;
    for (int i = 0; i < pattern.length(); i++)
    {
        if (pattern[i] == '(' || pattern[i] == '{' || pattern[i] == '[')
            validator.push(pattern[i]);
        else
        {
            char top = validator.top();
            validator.pop();
            if (top == pattern[i])
            {
                validator.pop();
                cout << "No";
                break;
            }
        }
    }
    if (validator.empty())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}