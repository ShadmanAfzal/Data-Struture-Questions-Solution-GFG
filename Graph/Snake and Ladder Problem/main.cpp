#include <bits/stdc++.h>
using namespace std;

class Move
{
public:
    int v;
    int distance;
};

int minStep(int n,vector<int> &moveArray)
{
    queue<Move> q;
    vector<bool> visited(n, false);
    visited[0] = true;
    Move move;
    move.v = 0;
    move.distance = 0;
    q.push(move);
    Move top;
    while (!q.empty())
    {
        top = q.front();
        q.pop();


        if(top.v == n-1)
            break;

        for(int i=top.v+1; i <= (top.v + 6) && i<n; ++i){
            if(!visited[i]){
                Move move;
                move.distance = top.distance + 1;
                visited[i] = true;

                if(moveArray[i] != -1){
                    move.v = moveArray[i];
                }
                else
                    move.v = i;
                q.push(move);
            }
        }
    }

    return top.distance;
}

int main()
{
    int N = 30;
    vector<int> moves(N,-1);
    
    // Ladder
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
  
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout<<minStep(N,moves)<<endl;
}