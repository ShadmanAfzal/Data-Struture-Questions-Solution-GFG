#include <bits/stdc++.h>
using namespace std;

class  Move{
public:
    int x,y;
    Move(){}
    Move(int x,int y){
        this->x = x;
        this->y = y;
    }
};

bool isValid(int i,int j,int row,int col, vector<vector<int> > images)
{
    return (i>=0 and i<row and j>=0 and j<col and images[i][j]==1);
}

void floodFill(int row,int col,vector<vector<int> > &images,int x, int y){
    queue<Move> q;
    Move move;
    q.push(Move(x,y));
    while(!q.empty()){
        move = q.front();
        q.pop();
        if(isValid(move.x,move.y,row,col,images)){
            images[move.x][move.y] = 2;
            q.push(Move(move.x+1,move.y));
            q.push(Move(move.x-1,move.y));
            q.push(Move(move.x,move.y+1));
            q.push(Move(move.x,move.y-1));
        }
    }
}

int main(){
    int n,m;
    n = 10;
    m = 10;
    vector<vector<int> > images(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>images[i][j];
        }
    }
    floodFill(n,m,images,1,1);
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<images[i][j]<<" ";
        }
        cout<<endl;
    }
}