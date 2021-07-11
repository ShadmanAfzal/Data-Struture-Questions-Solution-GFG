#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s)
    {
        stack<char> vowel;
        string reverse = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (!isVowel(s[i]))
            {
                reverse += s[i];
            }
            else
            {
                reverse += '#';
                vowel.push(s[i]);
            }
        }
        int j = 0;
        while (!vowel.empty())
        {
            if (reverse[j] == '#')
            {
                char temp = vowel.top();
                vowel.pop();
                reverse[j] = temp;
            }
            j++;
        }

        return reverse;
    }
};

int main()
{
    Solution sol;
    cout<<sol.reverseVowels("aA");
}