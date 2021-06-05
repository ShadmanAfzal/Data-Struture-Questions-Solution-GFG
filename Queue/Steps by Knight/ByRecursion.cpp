#include <bits/stdc++.h>
using namespace std;

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool isvisited[100][100] = {false};

static bool validate(int a, int b, int n)
{
    if (a >= 0 && a < n && b >= 0 && b < n && !isvisited[a][b])
        return true;
    return false;
}

int solve(int a, int b, int x, int y, int n)
{
    if (!validate(a, b, n))
        return 999999;
    if (a == x && b == y)
    {
        return 0;
    }
    isvisited[a][b] = true;
    int a1 = solve(a + dx[0], b + dy[0], x, y, n) + 1;
    int a2 = solve(a + dx[1], b + dy[1], x, y, n) + 1;
    int a3 = solve(a + dx[2], b + dy[2], x, y, n) + 1;
    int a4 = solve(a + dx[3], b + dy[3], x, y, n) + 1;
    int a5 = solve(a + dx[4], b + dy[4], x, y, n) + 1;
    int a6 = solve(a + dx[5], b + dy[5], x, y, n) + 1;
    int a7 = solve(a + dx[6], b + dy[6], x, y, n) + 1;
    int a8 = solve(a + dx[7], b + dy[7], x, y, n) + 1;
    isvisited[a][b] = false;
    return min(min(min(a1, a2), min(a3, a4)), min(min(a5, a6), min(a7, a8)));
}

int main()
{
    int n = 6;
    cout << solve(0, 0, 5, 5, n) << endl;
}