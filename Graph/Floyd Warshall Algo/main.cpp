#include <bits/stdc++.h>
#define INF INT_MAX
#define N 4
using namespace std;

void FloydWarshallAlgo(int graph[N][N])
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(i==j || k==i || k==j)
                    continue;
                if (graph[i][j] > (graph[i][k] + graph[k][j]) and (graph[i][k] != INF and graph[k][j] != INF))
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int graph[N][N] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    FloydWarshallAlgo(graph);
}