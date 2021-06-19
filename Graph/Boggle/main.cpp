#include <bits/stdc++.h>
using namespace std;


void solve(vector<string> dic,int boggle [3][3]){

    for(int i=0;i<dic.size();i++){
        string s = dic[i];

        queue<char> q;
        q.push(s[0]);
        vector<bool> isvisited(9,false);

        
    }

}

int main()
{
    vector<string> dic;
    dic.push_back("GEEKS");
    dic.push_back("FOR");
    dic.push_back("QUIZ");
    dic.push_back("GO");

    char boggle[3][3] = {{'G', 'I', 'Z'},
                         {'U', 'E', 'K'},
                         {'Q', 'S', 'E'}};

    
}