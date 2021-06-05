#include <bits/stdc++.h>
using namespace std;

class cell
{
    public:
    int x,y;
    int distance;
    cell(){}
    cell(int x,int y,int distance)
    {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};

bool isValid(int x,int y,int N)
{
    if(x>=0 && x<N && y>=0 && y<N)
        return true;
    return false;
}

int minStepToReachGoal(int x,int y,int a,int b,int N)
{
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    queue<cell> q;
    
    q.push(cell(x,y,0));

    cell t;
    int d1,d2;
    int isVisited[N][N]={false};

    while(!q.empty())
    {
        t = q.front();
        q.pop();
        
        if(t.x == a && t.y == b)
            return t.distance;

        for(int i=0;i<8;i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if(isValid(x,y,N))
            {
                isVisited[x][y] = true;
                q.push(cell(x,y,t.distance+1));
            }

        }
    }
}

int main()
{
    int N = 5;
    cout<<minStepToReachGoal(0,0,3,4,N);
}