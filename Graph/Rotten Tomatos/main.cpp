#include <bits/stdc++.h>
using namespace std;

class Moves
{
public:
    int x;
    int y;
};

bool issafe(int i, int j)
{
    if (i >= 0 && i < 3 && j >= 0 && j < 5)
        return true;
    return false;
}

bool isdelim(Moves temp)
{
    return (temp.x == -1 && temp.y == -1);
}

bool checkall(int arr[][5])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            if (arr[i][j] == 1)
                return true;
    return false;
}

int getMinTime(queue<Moves> q, int arr[3][5])
{
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    Moves temp;
    int ans = 0;
    while (!q.empty())
    {
        bool flag = false;
        while (!isdelim(q.front()))
        {
            temp = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (issafe(temp.x + dx[i], temp.y + dy[i]) && arr[temp.x + dx[i]][temp.y + dy[i]] == 1)
                {
                    arr[temp.x + dx[i]][temp.y + dy[i]] = 2;
                    if (!flag)
                    {
                        flag = true;
                        ans++;
                        temp.x = temp.x + dx[i];
                        temp.y = temp.y + dy[i];
                        q.push(temp);
                    }
                }
            }
            q.pop();

            if (!q.empty())
            {
                temp.x = -1;
                temp.y = -1;
                q.push(temp);
            }
        }

        return !checkall(arr) ? -1 : ans;
    }
}
int main()
{
    int grid[3][5] = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};
    queue<Moves> q;
    Moves moves;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (grid[i][j] == 2)
            {
                moves.x = i;
                moves.y = j;
                q.push(moves);
            }
        }
    }
    moves.x = -1;
    moves.y = -1;
    q.push(moves);
    cout << getMinTime(q, grid);
}