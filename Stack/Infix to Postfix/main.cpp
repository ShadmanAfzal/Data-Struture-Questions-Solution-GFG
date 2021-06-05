#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostFix(string s)
{
    stack<char> st;
    st.push('N');
    int l = s.length();
    string output;
    for (int i = 0; i < l; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            output += s[i];
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            while (st.top() != 'N' && st.top() != '(')
            {
                char top = st.top();
                st.pop();
                output += top;
            }
            if (st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        else
        {
            while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                output += c;
            }
            st.push(s[i]);
        }
    }
    while (st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        output += c;
    }
    cout << output << endl;
}

int main()
{
    string exp = "a*-(b+c)";
    infixToPostFix(exp);
    return 0;
}