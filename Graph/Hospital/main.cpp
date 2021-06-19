// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Move
{
public:
    int x;
    int y;
};

class Solution
{
public:
    bool checkAll(vector<vector<int> > hospital)
    {
        int row = hospital.size();
        int col = hospital[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (hospital[i][j] == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool islimiter(Move m)
    {
        if (m.x == -1 and m.y == -1)
        {
            return true;
        }
        return false;
    }

    bool isVisited(int i, int j, int row, int col)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        return false;
    }

    int helpaterp(vector<vector<int> > hospital)
    {
        int ans = 0;
        int row = hospital.size();
        int col = hospital[0].size();
        queue<Move> q;
        Move m;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (hospital[i][j] == 2)
                {
                    m.x = i;
                    m.y = j;
                    q.push(m);
                }
            }
        }

        m.x = -1;
        m.y = -1;
        q.push(m);
        while (!q.empty())
        {
            bool FLAG = false;
            while (!islimiter(q.front()))
            {
                m = q.front();
                q.pop();
                cout << m.x << " ";
                if (isVisited(m.x + 1, m.y, row, col) && hospital[m.x +1][m.y] == 1)
                {
                    if (!FLAG)
                        ans++, FLAG = true;
                    hospital[m.x + 1][m.y] = 2;
                    m.x++;
                    q.push(m);
                    m.x--;
                }
                if (isVisited(m.x, m.y + 1, row, col) && hospital[m.x][m.y + 1] == 1)
                {
                    if (!FLAG)
                        ans++, FLAG = true;
                    hospital[m.x][m.y + 1] = 2;
                    m.y++;
                    q.push(m);
                    m.y--;
                }
                if (isVisited(m.x - 1, m.y, row, col) && hospital[m.x +1][m.y] == 1)
                {
                    if (!FLAG)
                        ans++, FLAG = true;
                    hospital[m.x + 1][m.y] = 2;
                    m.x--;
                    q.push(m);
                    m.x++;
                }
                if (isVisited(m.x, m.y - 1, row, col) && hospital[m.x][m.y - 1] == 1)
                {
                    if (!FLAG)
                        ans++, FLAG = true;
                    hospital[m.x ][m.y -1 ] = 2;
                    m.y--;
                    q.push(m);
                }
            }
            q.pop();
            if (!q.empty())
            {
                m.x = -1;
                m.y = -1;
                q.push(m);
            }
        }

        return checkAll(hospital) ? ans : -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;
        int C;

        cin >> R >> C;
        vector<vector<int> > hospital;
        int i, j;
        for (i = 0; i < R; i++)
        {
            vector<int> temp;
            for (j = 0; j < C; j++)
            {
                int k;
                cin >> k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
        }

        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends