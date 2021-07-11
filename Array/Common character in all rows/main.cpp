#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> hash;
    vector<vector<int>> matrix{
        {1, 2, 3, 4, 5},
        {2, 4, 5, 8, 10},
        {3, 5, 7, 9, 11},
        {1, 3, 5, 7, 9},
    };
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++){
        for(int j=0;j< col; j++){
            hash[matrix[i][j]]++;
        }
    }
    for(auto i : hash){
        if(i.second==matrix.size())
            cout<<i.first<<endl;
    }
}